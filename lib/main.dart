import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/material.dart';
import 'package:food_delivery_app/Services/authentication/auth_gate.dart';
//import 'login or register pageeeeee';
import'register_page.dart';
import 'login_page.dart';
import 'package:food_delivery_app/register_page.dart';
import 'package:food_delivery_app/login_page.dart';
import 'package:food_delivery_app/firebase_options.dart';
import 'package:food_delivery_app/restaurant.dart';
import 'package:food_delivery_app/theme_provider.dart';
import 'package:provider/provider.dart';
void main() async{
WidgetsFlutterBinding.ensureInitialized();
await Firebase.initializeApp(options: DefaultFirebaseOptions.currentPlatform);


  runApp(
    MultiProvider(providers: [
      //theme
      ChangeNotifierProvider(create: (context) => ThemeProvider()),
      //rest.
      ChangeNotifierProvider(create: (context) => Restaurant()),
    ],
      child: const MyApp(),
    )
  );
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: const AuthGate(),
      theme: Provider.of<ThemeProvider>(context).themeData,
    );
  }
}