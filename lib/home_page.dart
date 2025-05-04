import 'package:flutter/material.dart';
import 'package:food_delivery_app/food.dart';
import 'package:food_delivery_app/food_page.dart';
import 'package:food_delivery_app/my_current_location.dart';
import 'package:food_delivery_app/my_description_box.dart';
import 'package:food_delivery_app/my_drawer.dart';
import 'package:food_delivery_app/my_food_tile.dart';
import 'package:food_delivery_app/my_sliver_app_bar.dart';
import 'package:food_delivery_app/my_tab_bar.dart';
import 'package:food_delivery_app/restaurant.dart';
import 'package:provider/provider.dart';
class HomePage extends StatefulWidget {
  const HomePage({super.key});

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> with SingleTickerProviderStateMixin{
  late TabController _tabController;

  @override
  void initState() {
    // TODO: implement initState
    super.initState();
    _tabController= TabController(length: FoodCategory.values.length, vsync: this);
  }
  @override
  void dispose() {
    _tabController.dispose();
    super.dispose();
  }
//return items that belong to their specific category only.
  List<Food> _filterMenuByCategory(FoodCategory category, List<Food> fullMenu){
    return fullMenu.where((food) => food.category == category).toList();
  }
//return these list of food in their specified category.
  List<Widget> getFoodInThisCategory(List<Food> fullMenu) {
    return FoodCategory.values.map((category) {
      //get the category
      List<Food> categoryMenu = _filterMenuByCategory(category, fullMenu);
      return ListView.builder(
        itemCount: categoryMenu.length,
        physics: const NeverScrollableScrollPhysics(),
        padding: EdgeInsets.zero,
        itemBuilder: (context, index) {
          //get each food
          final food=categoryMenu[index];

          //return the food tile shape.
          return FoodTile(
            food: food,
            onTap: () => Navigator.push(context, MaterialPageRoute(builder: (context) =>FoodPage(food: food),
          )
          ),
          );
        },
      );
    }).toList();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      drawer: MyDrawer(),
      body: NestedScrollView(headerSliverBuilder: (context,innerBoxIsScrolled)=>[
        MySliverAppBar(
            title: MyTabBar(tabController: _tabController),
            child: Column(
              mainAxisAlignment: MainAxisAlignment.end,
              children: [
                Divider(indent: 25,endIndent: 25,color: Theme.of(context).colorScheme.secondary,),

                //my curr loc
                 MyCurrentLocation(),

                //desc box
                const MyDescriptionBox(),
              ],
            )
        ),
      ],
      body: Consumer<Restaurant>(builder: (context,restaurant, child) => TabBarView(
          controller: _tabController,
          children: getFoodInThisCategory(restaurant.menu)
      ),) 
      )
    );
  }
}
