<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "database";
session_start();
$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$name = $_POST['name'];
$email = $_POST['email'];
$password = $_POST['password'];
$phoneNumber = $_POST['number'];
$address= $_POST['address'];

$emailExistsQuery = "SELECT * FROM customer WHERE email = '$email'";
$emailExistsResult = $conn->query($emailExistsQuery);
if ($emailExistsResult->num_rows > 0) {
    $existingUser = $emailExistsResult->fetch_assoc();
    $_SESSION['customer_id'] = $existingUser['id'];
    $_SESSION['customer_name'] = $existingUser['name'];
    header("Location: http://localhost/Web/catalog.php");
    exit();
}

$sql = "INSERT INTO customer(name, email, password, number, address) VALUES ('$name', '$email', '$password','$phoneNumber','$address')";

if ($conn->query($sql) === TRUE) {
    $customer_id = $conn->insert_id; 
    $_SESSION['customer_id'] = $customer_id;
    $_SESSION['customer_name'] = $name;
    
    echo "New record created successfully";   
    header("Location: http://localhost/Web/catalog.php");
    exit(); 
} else {
    echo "Error: " . "<br>" . $conn->error;
}

$conn->close();
?>
