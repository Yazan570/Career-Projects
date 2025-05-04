import 'package:flutter/material.dart';
import 'package:food_delivery_app/food.dart';

class CartItem{
  Food food;
  List<Addon> selectedAddons;
  int quantity;

  CartItem({required this.food, required this.selectedAddons, this.quantity=1});
  double get totalPrice{
    //add the addons alone
    double addonsPrice = selectedAddons.fold(0, (sum,addon) => sum+addon.price);
    //return addons and food price depending on the quantity.
    return (food.price+addonsPrice)*quantity;
  }
}