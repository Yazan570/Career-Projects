import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:food_delivery_app/Services/authentication/auth_service.dart';
import 'package:food_delivery_app/my_button.dart';
import 'package:food_delivery_app/my_textfield.dart';
import 'package:food_delivery_app/home_page.dart';
class LoginPage extends StatefulWidget
{
  final void Function()? onTap;

  const LoginPage({super.key,required this.onTap});

  @override
  State<LoginPage> createState() => _LoginPageState();

}




class _LoginPageState extends State<LoginPage>
{

  final TextEditingController emailController = TextEditingController();
  final TextEditingController passwordController = TextEditingController();

void login() async{
  final _authService = AuthService();
  
  try{
    await _authService.signInWithEmailPassword(emailController.text,passwordController.text);
  }
   catch(e){
    String ex ='';
    for(int i=11;i<e.toString().length;i++)
      {
        ex+= e.toString()[i];
      }

    if(ex == 'invalid-credential')
      {
        ex = 'invalid-password';
      }




    showDialog(context: context,
        builder:(context)=>AlertDialog(
          title: Text(ex),
        ));
  }
}

void forgotPw()
{
  showDialog(context: context,
      builder: (context)=>AlertDialog(
        backgroundColor: Theme.of(context).colorScheme.background,
        title: const Text("User Tapped forgot password."),
      ));
}

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        backgroundColor: Theme
            .of(context)
            .colorScheme
            .background,
        body: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              // will it be centered on the mobile screen ?????
              Icon(
                Icons.lock_clock_rounded,
                size: 100,
                color: Theme
                    .of(context)
                    .colorScheme
                    .inversePrimary,
              ),
              const SizedBox(height: 25,),
              Text('yazBox Delivery',
                style: TextStyle(
                  fontSize: 16,
                  color: Theme.of(context).colorScheme.inversePrimary,
                ),
              ),
              const SizedBox(height: 25,),

              //email text field
              MyTextField(
                controller: emailController,
                hintText: 'Email',
                obscureText: false,
              ),
              const SizedBox(height: 10,),
              MyTextField(
                controller: passwordController,
                hintText: 'Password',
                obscureText: true,
              ),

              const SizedBox(height: 10,),

              MyButton(text: 'Sign In',onTap: login,),
              const SizedBox(height: 25,),

              Row(
                mainAxisAlignment:  MainAxisAlignment.center,
                children: [
                  Text('Not a member?',
                    style: TextStyle(color: Theme.of(context).colorScheme.inversePrimary),),
                  const SizedBox(width: 4,),
                  GestureDetector(
                      onTap: widget.onTap,
                      child: Text( 'Register Now',
                        style: TextStyle(color: Theme.of(context).colorScheme.inversePrimary,fontWeight: FontWeight.bold),)
                  )
                ],
              )

            ]
        )
    );
  }
}