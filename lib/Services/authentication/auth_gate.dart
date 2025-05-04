// this page is to check whether the current user is logged in or not

import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:food_delivery_app/home_page.dart';
import 'login_or_register.dart';

class AuthGate extends StatelessWidget{
  const AuthGate({super.key});

  @override
  Widget build(BuildContext context) {
  return Scaffold(
    body: StreamBuilder(stream: FirebaseAuth.instance.authStateChanges(), builder: (context,snapshot){
      if(snapshot.hasData)
        {
          return const HomePage();
        }
      else
        {
          return const LoginOrRegister();
        }
    },


    ),


  );
  }


}