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
$customer_id=$_SESSION['customer_id'];
$quantity=1;
$sql = "INSERT INTO cart(customer_id, product_id, quantity) VALUES ('$customer_id', '', '$quantity')";


?>