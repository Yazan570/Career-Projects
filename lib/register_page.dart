import 'package:flutter/material.dart';
import 'package:food_delivery_app/Services/authentication/auth_service.dart';
import 'package:food_delivery_app/my_button.dart';
import 'package:food_delivery_app/my_textfield.dart';

class RegisterPage extends StatefulWidget{
  final void Function()? onTap;
  const RegisterPage({super.key, required this.onTap});
  @override
  State<RegisterPage> createState() => _RegisterPageState();
}

class _RegisterPageState extends State<RegisterPage> {
  final TextEditingController emailController = TextEditingController();
  final TextEditingController passwordController = TextEditingController();
  final TextEditingController confirmPasswordController = TextEditingController();

    void register() async{
   
      final _authService = AuthService();
      
      if(passwordController.text == confirmPasswordController.text)
        {
          try{
            await _authService.signUpWithEmailPassword(emailController.text, passwordController.text,);
          }

          catch(e){

            String ex ='';
            for(int i=11;i<e.toString().length;i++)
            {
              ex+= e.toString()[i];
            }

            showDialog(context: context,
                builder: (context)=>AlertDialog(
                  title: Text(ex),
                ),);
          }


        }

    else{
        showDialog(context: context,
            builder: (context)=>AlertDialog(
              title: Text("Passwords don't match!"),
            ));
      }
    }










  @override
  Widget build(BuildContext context){
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
              Text('Create your new account.',
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
              MyTextField(
                controller: confirmPasswordController,
                hintText: 'Confirm password',
                obscureText: true,
              ),
              const SizedBox(height: 10,),

              MyButton(text: 'Sign Up',onTap: register,),
              const SizedBox(height: 25,),

              Row(
                mainAxisAlignment:  MainAxisAlignment.center,
                children: [
                  Text('Already have an account?',
                    style: TextStyle(color: Theme.of(context).colorScheme.inversePrimary),),
                  const SizedBox(width: 4,),
                  GestureDetector(
                      onTap: widget.onTap,
                      child: Text( 'Login now',
                        style: TextStyle(color: Theme.of(context).colorScheme.inversePrimary,fontWeight: FontWeight.bold),)
                  )
                ],
              )

            ]
        ));
  }
}