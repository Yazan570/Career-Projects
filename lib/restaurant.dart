//library for the function 1st where or null
import 'package:collection/collection.dart';
import 'package:flutter/cupertino.dart';
import 'package:food_delivery_app/cart_item.dart';
import 'package:food_delivery_app/food.dart';
import 'package:intl/intl.dart';
class Restaurant extends ChangeNotifier{
  //list of food menu
  final List<Food> _menu=[
    //burgers ------------------------------------------------------
    Food(name: "Classic Cheeseburger", price: 5.50, imagePath: "lib/images/burgers/Cheese_burger.jpg", description: "Classic yazbox cheese burger, juicy beef patty with melted cheddar, lettuce, tomato, and a hint of onion and pickle.", category: FoodCategory.burgers, availableAddons: [
      Addon(name: "Extra cheese", price: 0.50),
      Addon(name: "Extra patty", price: 1.99),
      Addon(name: "Bacon", price: 0.99),
    ],
  ),
    Food(name: "BBQ Bacon Burger", price: 6.50, imagePath: "lib/images/burgers/bbq_burger.png", description: "Smoked beef, smoked bacon, lettuce, tomato, melted cheddar, and our special box sauce.", category: FoodCategory.burgers, availableAddons: [
      Addon(name: "Extra cheese", price: 0.50),
      Addon(name: "Extra patty", price: 1.99),
      Addon(name: "onion rings", price: 0.99),
    ],
    ),
    Food(name: "Bluemoon Burger", price: 5.50, imagePath: "lib/images/burgers/bluemoon_burger.webp", description: "Our fresh Angus beef patty, our special bluemoon sauce, melted cheddar, and more. (Served with corn)", category: FoodCategory.burgers, availableAddons: [
      Addon(name: "Extra cheese", price: 0.50),
      Addon(name: "Extra patty", price: 1.99),
      Addon(name: "Bacon", price: 0.99),
      Addon(name: "Swiss Cheese", price: 0.99),
    ],
    ),
    Food(name: "Hawaiian Burger", price: 6.99, imagePath: "lib/images/burgers/hawaiian_burger.jpg", description: "A juicy beef patty with melted cheddar, lettuce, tomato, pineapple, and bacon.", category: FoodCategory.burgers, availableAddons: [
      Addon(name: "Extra cheese", price: 0.50),
      Addon(name: "Extra patty", price: 1.99),
      Addon(name: "Avocado", price: 1.99),
    ],
    ),
    Food(name: "Vege Burger", price: 6.50, imagePath: "lib/images/burgers/vege_burger.jpg", description: "Beef patty, lettuce, tomato, pickles, onion, cheddar, cabbage, and ketchup.", category: FoodCategory.burgers, availableAddons: [
      Addon(name: "Extra cheese", price: 0.50),
      Addon(name: "Extra patty", price: 1.99),
      Addon(name: "Avocado", price: 1.99),
    ],
    ),
    //salads ---------------------------------------------------------
    Food(name: "Caesar Salad", price: 2.99, imagePath: "lib/images/salads/Caesar_salad.jpg", description: "Original Caesar salad, typical ingredients.", category: FoodCategory.salads, availableAddons: [
      Addon(name: "Extra parmesan", price: 0.50),
      Addon(name: "Extra chicken", price: 1.99),
      Addon(name: "Avocado", price: 1.99),
    ],
    ),
    Food(name: "Coleslaw", price: 0.99, imagePath: "lib/images/salads/coleslaw.jpg", description: "Just a Coleslaw.", category: FoodCategory.salads, availableAddons: [
      Addon(name: "Extra parmesan", price: 0.50),
    ],
    ),
    Food(name: "Fruit Salad", price: 2.99, imagePath: "lib/images/salads/fruit_salad.jpg", description: "Kiwi, Berries, Orange, banana, and more.", category: FoodCategory.salads, availableAddons: [
      Addon(name: "Honey", price: 0.50),
      Addon(name: "Extra strawberry", price: 1.99),
      Addon(name: "Extra Avocado", price: 1.99),
    ],
    ),
    Food(name: "Green Salad", price: 1.50, imagePath: "lib/images/salads/green_salad.jpg", description: "Avocado, lettuce, and more greenish vegies.", category: FoodCategory.salads, availableAddons: [
      Addon(name: "Extra Avocado", price: 1.99),
    ],
    ),
    Food(name: "Protein Salad", price: 4.50, imagePath: "lib/images/salads/protein_salad.jpg", description: "A special one for our gym buddies, contains 25g of protein.", category: FoodCategory.salads, availableAddons: [
      Addon(name: "Extra parmesan", price: 0.50),
      Addon(name: "Avocado", price: 1.99),
    ],
    ),

    //desserts -------------------------------------------------------
    Food(name: "Cheesecake", price: 2.50, imagePath: "lib/images/desserts/cheese_cake.jpg", description: "A special tasty cheesecake.", category: FoodCategory.desserts, availableAddons: [
      Addon(name: "Strawberry sauce", price: 0.99),
    ],
    ),
    Food(name: "Cinnamon Roll", price: 2.99, imagePath: "lib/images/desserts/cinnamon_roll.jpg", description: "Classic Cinnamon roll.", category: FoodCategory.desserts, availableAddons: [
      Addon(name: "Chocolate", price: 0.50),
      Addon(name: "Promote to a large one", price: 0.99),
    ],
    ),
    Food(name: "Nutella Croissant", price: 3.99, imagePath: "lib/images/desserts/nutella_croissant.jpg", description: "Fully loaded croissant with nutella and bananas.", category: FoodCategory.desserts, availableAddons: [
      Addon(name: "Extra Nutella", price: 0.50),
      Addon(name: "Avocado", price: 1.99),
    ],
    ),
    Food(name: "Salted Caramel Icecream", price: 1.99, imagePath: "lib/images/desserts/salted_caramel_icecream.jpg", description: "2 Scoops of salted caramel with a breeze of hazelnuts.", category: FoodCategory.desserts, availableAddons: [
      Addon(name: "Extra Scoop", price: 0.50),
    ],
    ),
    Food(name: "Volcano Cake", price: 3.99, imagePath: "lib/images/desserts/volcano_cake.webp", description: "Our special volcano cake.", category: FoodCategory.desserts, availableAddons: [
      Addon(name: "Extra Chocolate", price: 0.50),
    ],
    ),

    //sides ----------------------------------------------------------
    Food(name: "Chicken Soup", price: 2.50, imagePath: "lib/images/sides/chicken_soup.webp", description: "Hot chicken soup served with basil.", category: FoodCategory.sides, availableAddons: [
      Addon(name: "Parmesan", price: 0.50),
    ],
    ),
    Food(name: "Chili Fries", price: 4.50, imagePath: "lib/images/sides/chili_fries.jpg", description: "The most wanted side dish, fries, beef, cheese and more!", category: FoodCategory.sides, availableAddons: [
      Addon(name: "Extra cheese", price: 0.50),
      Addon(name: "Extra beef", price: 0.99),
      Addon(name: "Extra Spices", price: 0.50),
    ],
    ),
    Food(name: "Dynamite Shrimp", price: 2.99, imagePath: "lib/images/sides/dynamite_shrimp.jpg", description: "Original classic dynamite shrimp with our special spices.", category: FoodCategory.sides, availableAddons: [
      Addon(name: "Extra Spicy", price: 0.50),
      Addon(name: "Extra Dynamite", price: 0.50),
    ],
    ),
    Food(name: "Mashed Potato", price: 1.90, imagePath: "lib/images/sides/mashed_potato.webp", description: "Fresh mashed potatoes.", category: FoodCategory.sides, availableAddons: [
      Addon(name: "Parmesan", price: 0.50),
    ],
    ),
    Food(name: "Mozzarella Sticks", price: 1.99, imagePath: "lib/images/sides/mozzarella_sticks.jpg", description: "Fried mozzarella sticks with ketchup on the side.", category: FoodCategory.sides, availableAddons: [
      Addon(name: "Parmesan", price: 0.50),
      Addon(name: "Onion Rings", price: 0.99),
    ],
    ),

    //drinks ---------------------------------------------------------
    Food(name: "Apple Juice", price: 1.50, imagePath: "lib/images/drinks/apple_juice.jpg", description: "Fresh cold apple juice.", category: FoodCategory.drinks, availableAddons: [
      Addon(name: "Lemon", price: 0.30),
    ],
    ),
    Food(name: "Cola", price: 0.99, imagePath: "lib/images/drinks/cola.jpg", description: "Cola with ice.", category: FoodCategory.drinks, availableAddons: [
      Addon(name: "Promote to large", price: 0.50),
    ],
    ),
    Food(name: "Orange Juice", price: 1.50, imagePath: "lib/images/drinks/orange_juice.jpg", description: "Fresh cold orange juice.", category: FoodCategory.drinks, availableAddons: [
      Addon(name: "Lemon", price: 0.30),
    ],
    ),
    Food(name: "Passion Juice", price: 1.85, imagePath: "lib/images/drinks/passion_fruit_juice.png", description: "Fresh cold passion fruit juice.", category: FoodCategory.drinks, availableAddons: [
      Addon(name: "Lemon", price: 0.30),
      Addon(name: "Honey", price: 0.30),
    ],
    ),
    Food(name: "Slash", price: 1.50, imagePath: "lib/images/drinks/slash.webp", description: "Frozen flavourful slash.", category: FoodCategory.drinks, availableAddons: [
      Addon(name: "Lemon", price: 0.30),
      Addon(name: "Strawberry", price: 0.50),
      Addon(name: "Mint", price: 0.30),
    ],
    ),
  ];

  //user cart
  final List<CartItem> _cart = [];


  //delivery address (which user can change/update)
  String _deliveryAddress = 'Amman, Jordan';


  /*
  G E T T E R S
  */
    List<Food> get menu => _menu;
    List<CartItem> get cart => _cart;

    String get deliveryAddress=> _deliveryAddress;


  /*
  O P E R A T I O N S
  */



//add to cart
void addToCart(Food food, List<Addon> selectedAddons){
  //see if there's a cart item already with the same food and selected addons.
  CartItem? cartItem = _cart.firstWhereOrNull((item) {
    //check if the food items are the same
    bool isSameFood = item.food == food;

    //check if the list of addons are the same
    bool isSameAddon = ListEquality().equals(item.selectedAddons, selectedAddons);
    return isSameAddon&&isSameFood;
  });
  //if item is already there in the cart, just increase its quantity.
  if(cartItem!=null){
    cartItem.quantity++;
  }

  //else add a new item to the cart.
  else{
    _cart.add(CartItem(food: food, selectedAddons: selectedAddons));
  }
  notifyListeners();
}

//remove from cart

void removeFromCart(CartItem cartItem){
  int cartIndex = _cart.indexOf(cartItem);
  if(cartIndex!=-1){
    if(_cart[cartIndex].quantity>1){
      _cart[cartIndex].quantity--;
    }
    else{
      _cart.removeAt(cartIndex);
    }
  }
  notifyListeners();
}

//get total price
double getTotalPrice(){
  double total=0;
  for(CartItem cartItem in _cart){
    double itemTotal=cartItem.food.price;
    for(Addon addon in cartItem.selectedAddons){
      itemTotal+=addon.price;
    }
    total+=itemTotal*cartItem.quantity;
  }
  return total+0.99;
}

//total # of items in the cart
int getTotalItemCount(){
  int totalItemCount=0;
  for(CartItem cartItem in _cart){
    totalItemCount+=cartItem.quantity;
  }
  return totalItemCount;
}

//clear cart

void clearCart(){
  _cart.clear();
  notifyListeners();
}

// update delivery address
  void updateDeliveryAddress(String newAddress)
  {
    _deliveryAddress = newAddress;
    notifyListeners();
  }


  /*
  H E L P E R S
  */

//generate a receipt
String displayCartReceipt(){
  //string buffer has its own functions and helps me to create a whole long string.
  final receipt = StringBuffer();
  receipt.writeln("Here's your receipt.");
  receipt.writeln();

  //format the date to include up to seconds only(included from terminal using: flutter pub add intl).
  String formattedDate = DateFormat('yyyy-MM-dd HH:mm:ss').format(DateTime.now());

  receipt.writeln(formattedDate);
  receipt.writeln();
  receipt.writeln("----------");
  //move through each cart item and print them out.
  for(final cartItem in _cart){
    receipt.writeln("${cartItem.quantity} x ${cartItem.food.name} - ${_formatPrice(cartItem.food.price)}");
    if(cartItem.selectedAddons.isNotEmpty){
      receipt.writeln("    Add-ons: ${_formatAddons(cartItem.selectedAddons)}");
    }
    receipt.writeln();
  }

    receipt.writeln("----------");
    receipt.writeln();
    receipt.writeln("Total Items: ${getTotalItemCount()}");
    receipt.writeln("Total Price: ${_formatPrice(getTotalPrice())}");
    receipt.writeln();
    receipt.writeln("Delivering to: $deliveryAddress");

    return receipt.toString();
}

//format double value into money
String _formatPrice(double price){
  return "${price.toStringAsFixed(2)}JDs";
}
//format list of addons into a string summary
String _formatAddons(List<Addon> addons){
  return addons.map((addon) => "${addon.name} (${_formatPrice(addon.price)})").join(", ");
}
}