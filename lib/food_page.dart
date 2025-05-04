import 'package:flutter/material.dart';
import 'package:food_delivery_app/my_button.dart';
import 'package:food_delivery_app/restaurant.dart';
import 'package:provider/provider.dart';
import 'food.dart';

class FoodPage extends StatefulWidget {
  final Food food;
  //map for selected addons
  final Map<Addon, bool> selectedAddons = {};

   FoodPage({super.key,required this.food}){
     //initialize all to false as unselected
     for(Addon addon in food.availableAddons){
       selectedAddons[addon]=false;
     }
   }

  @override
  State<FoodPage> createState() => _FoodPageState();
}

class _FoodPageState extends State<FoodPage> {

  //add to cart method
  void addToCart(Food food, Map<Addon,bool> selectedAddons){
    //close the food page and go back to the menu.
    Navigator.pop(context);

    
    List<Addon> currentSelectedAddons=[];
    for(Addon addon in widget.food.availableAddons){
      if(widget.selectedAddons[addon]==true){
        currentSelectedAddons.add(addon);
      }
    }
    //access restaurant and add the food to the cart.
    context.read<Restaurant>().addToCart(food, currentSelectedAddons);
  }

  @override
  Widget build(BuildContext context) {
    return Stack(
      children: [
        // scaffold
        Scaffold(
    body: SingleChildScrollView(
    child: Column(
    children: [
    //food image
    Container(
    width: 450,
    height: 330,
    child:Image.asset(widget.food.imagePath,fit: BoxFit.fill,),
    ),
    Padding(
    padding: const EdgeInsets.all(25.0),
    child: Column(
    crossAxisAlignment: CrossAxisAlignment.start,
    children: [
    //food name
    Text(widget.food.name,
    style: const TextStyle(
    fontWeight: FontWeight.bold, fontSize: 20,
    ),
    ),

    //food price
    Text("${widget.food.price.toString()} JDs",
    style: TextStyle(
    fontSize: 16,
    color: Theme.of(context).colorScheme.primary,
      ),
    ),
    const SizedBox(height: 10,),
    //food description
    Text(widget.food.description,),

    const SizedBox(height: 10,),

    Divider(color: Theme.of(context).colorScheme.secondary,),
    const SizedBox(height: 10,),
    //food addons
    Text("Add-ons", style: TextStyle(color: Theme.of(context).colorScheme.inversePrimary, fontSize: 16, fontWeight: FontWeight.bold),),

    const SizedBox(height: 10,),
    Container(
    decoration: BoxDecoration(
    border: Border.all(color: Theme.of(context).colorScheme.secondary),
    borderRadius: BorderRadius.circular(8),
    ),
    child: ListView.builder(
    shrinkWrap: true,
    physics: const NeverScrollableScrollPhysics(),
    padding: EdgeInsets.zero,
    itemCount: widget.food.availableAddons.length,
    itemBuilder: (context, index){
    //get individual addon

    Addon addon = widget.food.availableAddons[index];
    return CheckboxListTile(
    title: Text(addon.name),
    subtitle: Text("${addon.price.toString()} JDS", style: TextStyle(color: Theme.of(context).colorScheme.primary),),
    value: widget.selectedAddons[addon],
    onChanged: (bool? value){
    setState(() {
    widget.selectedAddons[addon]=value!;
    });
    },
    );
    },
    ),
    )
    ],
    ),
    ),


    //Add to Cart button
    MyButton(
    onTap: () => addToCart(widget.food, widget.selectedAddons),
    text: "Add to cart",
    ),

    const SizedBox(height: 25,),
    ],
    ),
    ),
    ),
        //back button

        //To avoid moving up the screen.
        SafeArea(
          //Opacity makes it look transparent.
          child: Opacity(
            opacity: 0.7,
            child: Container(
              margin: EdgeInsets.only(left: 5),
              decoration: BoxDecoration(
                  color: Theme.of(context).colorScheme.secondary,
                  shape: BoxShape.circle,
              ),
              child:IconButton(
                  onPressed: ()=> Navigator.pop(context),
                  icon: const Icon(Icons.arrow_back_ios_rounded),
              ) ,
            ),
          ),
        ),
      ],
    );
  }
}
