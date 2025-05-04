import 'package:flutter/material.dart';
import 'package:food_delivery_app/Services/database/firestore.dart';
import 'package:food_delivery_app/my_receipt.dart';
import 'package:food_delivery_app/restaurant.dart';
import 'package:provider/provider.dart';

class DeliveyProgressPage extends StatefulWidget {
  const DeliveyProgressPage({super.key});

  @override
  State<DeliveyProgressPage> createState() => _DeliveyProgressPageState();
}

class _DeliveyProgressPageState extends State<DeliveyProgressPage> {


FirestoreService db = FirestoreService();




  @override
  void initState()
  {
    super.initState();

    String receipt = context.read<Restaurant>().displayCartReceipt();
    db.saveOrderToDatabase(receipt);


  }



  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.transparent,
      ),
      bottomNavigationBar: _buildBottomNavBar(context),
      body: SingleChildScrollView(
        child: const Column(
          children: [
            MyReceipt(),
          ],
        ),
      ),
    );
  }

  //Custom Bottom Nav Bar - Message / Call the driver.
Widget _buildBottomNavBar(BuildContext context){
    return Container(
      height: 100,
      decoration: BoxDecoration(
        color: Theme.of(context).colorScheme.secondary,
        borderRadius: const BorderRadius.only(
          topLeft: Radius.circular(40),
          topRight: Radius.circular(40),
        ),
      ),
      padding: const EdgeInsets.all(25),
      child: Row(
        children: [
          //Driver profile pic.
          Container(
            decoration: BoxDecoration(
              color: Theme.of(context).colorScheme.background,
              shape: BoxShape.circle,
            ),
            child: IconButton(
                onPressed: (){},
                icon: const Icon(Icons.person),
            ),
          ),

          //driver details.
          Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Text(
                "Yousif Saddouq",
                style: TextStyle(
                  fontWeight: FontWeight.bold,
                  fontSize: 18,
                  color: Theme.of(context).colorScheme.inversePrimary,
                ),
              ),
              Text(
                  "Driver",
                style: TextStyle(
                  color: Theme.of(context).colorScheme.primary,
                ),
              ),
            ],
          ),
       const Spacer(),

       Row(
         children: [
           //message button
           Container(
             decoration: BoxDecoration(
               color: Theme.of(context).colorScheme.background,
               shape: BoxShape.circle,
             ),
             child: IconButton(
               onPressed: (){},
               icon: const Icon(Icons.message),
               color: Theme.of(context).colorScheme.primary,
             ),
           ),
          const SizedBox(width: 10,),
           //call button
           Container(
             decoration: BoxDecoration(
               color: Theme.of(context).colorScheme.background,
               shape: BoxShape.circle,
             ),
             child: IconButton(
               onPressed: (){},
               icon: const Icon(Icons.call),
               color: Colors.green,
             ),
           ),

         ],
       )
        ],
      ),
    );
}
}
