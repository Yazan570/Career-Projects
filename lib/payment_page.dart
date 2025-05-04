import 'package:flutter/material.dart';
import 'package:flutter_credit_card/flutter_credit_card.dart';
import 'package:food_delivery_app/my_button.dart';
import 'delivey_progress_page.dart';
class PaymentPage extends StatefulWidget {
  const PaymentPage({super.key});

  @override
  State<PaymentPage> createState() => _PaymentPageState();
}

class _PaymentPageState extends State<PaymentPage> {
  GlobalKey<FormState> formKey = GlobalKey<FormState>();
  String cardNumber = '';
  String expiryDate = '';
  String cardHolderName = '';
  String cvvCode = '';
  bool isCvvFocused = false;


  //user wants to pay
  void userTappedPay(){
    if(formKey.currentState!.validate()){
      //show dialogue if form is valid
      showDialog(context: context, builder: (context)=> AlertDialog(
        title: const Text("Confirm payment"),
        content: SingleChildScrollView(
          child: ListBody(
            children: [
              Text("Card Number: $cardNumber"),
              Text("Expiry Date: $expiryDate"),
              Text("Card Holder Name: $cardHolderName"),
              Text("CVV: $cvvCode"),
            ],
          ),
        ),
        actions: [
          //cancel
          TextButton(
              onPressed: ()=> Navigator.pop(context),
              child: Text("Cancel")
          ),
          //yes
          TextButton(
              onPressed: (){
                Navigator.pop(context);
                Navigator.push(context,MaterialPageRoute(builder: (context)=> DeliveyProgressPage()
                ),
                );
              },
              child: Text("Yes")
          ),
        ],
      ),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Theme.of(context).colorScheme.background,
      appBar: AppBar(
        backgroundColor: Colors.transparent,
        foregroundColor: Theme.of(context).colorScheme.inversePrimary,
        title: const Text("Checkout"),
      ),
      body: Column(
        children: [
          //credit cart(added from terminal)
          CreditCardWidget(
            cardNumber: cardNumber,
            expiryDate: expiryDate,
            cardHolderName: cardHolderName,
            cvvCode: cvvCode,
            showBackView: isCvvFocused,
            onCreditCardWidgetChange: (p0){},
          ),
          //credit card form
          CreditCardForm(cardNumber: cardNumber,
            expiryDate: expiryDate,
            cardHolderName: cardHolderName,
            cvvCode: cvvCode,
            onCreditCardModelChange: (data) {
              setState(() {
                cardNumber=data.cardNumber;
                expiryDate=data.expiryDate;
                cardHolderName=data.cardHolderName;
                cvvCode=data.cvvCode;
                isCvvFocused=data.isCvvFocused;
              });
            },
            formKey: formKey,

          ),

          const Spacer(),

          MyButton(text: "Pay now", onTap: userTappedPay,
          ),
          const SizedBox(height: 25,),
        ],
      ),
    );
  }
}
