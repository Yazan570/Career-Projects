<!DOCTYPE html>
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

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
     $customer_id = $_SESSION['customer_id'];
    $productId = 3;
    $quantity = 1; 
    $color = $_POST['Tcolor'];
    $size = $_POST['size'];

    $query = $conn->prepare("INSERT INTO cart (customer_id, product_id, quantity, color, size) VALUES (?, ?, ?, ?, ?)");
    $query->bind_param("iiiss", $customer_id, $productId, $quantity, $color, $size);

    if ($query->execute()) {
        echo "Product added to cart successfully";
    } else {
        echo "Error: " . $query->error;
    }

    $query->close();
    $conn->close();
}
?>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Catalog - 3LAWI FOR T-SHIRTS</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <header>
        <div class="logo"><img src="logo.png" height="100px"></div>
        <nav class="navbar">
            <ul>
                <li><a href="index.php">Home</a></li>
                <li><a href="catalog.php">Catalog</a></li>
                <li><a href="cart.php">Cart</a></li>
                <li><a href="checkout.php">Checkout</a></li>
                <li><a href="order-confirmation.php">Order Confirmation</a></li>
            </ul>
        </nav>
    </header>
    <div class="i1Desc">
    <img src="jacket.png" height="500px" width="400px" class="informationPicture">
    <form method="post" action="">
        <div class="radioButtons">
            <div class="colors">
            <input type="radio" name="Tcolor" id="b" class="radioColors">
            <label for="b"><div class="Black"></div></label>
            <input type="radio" name="Tcolor" id="w"class="radioColors">
            <label for="w"><div class="White"></div></label>
            <input type="radio" name="Tcolor" id="r"class="radioColors">
            <label for="r"><div class="Red"></div></label>
            <input type="radio" name="Tcolor" id="g"class="radioColors">
            <label for="g"><div class="Green"></div></label>
            <input type="radio" name="Tcolor" id="bl"class="radioColors">
            <label for="bl"><div class="Blue"></div></label>
            <input type="radio" name="Tcolor" id="v"class="radioColors">
            <label for="v"><div class="Violet"></div></label>
        </div>
        <div class="sizes">
            <label for="Xsmall"><div class="XS">XS</div></label>
            <input type="radio" name="size" id="Xsmall" class="radioSize">
            <label for="small"><div class="S">S</div></label>
            <input type="radio" name="size" id="small"class="radioSize">
            <label for="medium"><div class="M">M</div></label>
            <input type="radio" name="size" id="medium"class="radioSize">
            <label for="large"><div class="L">L</div></label>
            <input type="radio" name="size" id="large"class="radioSize">
            <label for="xLarge"><div class="XL">XL</div></label> 
            <input type="radio" name="size" id="xLarge"class="radioSize">
        </div>
        </div><br>
        <p><button class='add' onclick='addToCart(" . $row["product_id"] . ")'>Add to cart</button></p>";
        </form>
</div>
<div class="bigBoxItem">
    <p class="bigInfo">3LAWI Jacket, made in Iraq<br> Price: 45JD<br> Available sizes: <b>XS, S, M, L, XL</b>  (Sizes for kids coming soon)<br>
        Available colors: Black, Beige, Red, Green, Blue, Violet.
    </p>
</div>
    <footer>
        <p>&copy; 2024 3LAWI FOR T-SHIRTS. All rights reserved.</p>
    </footer>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="scripts.js" defer></script>
</body>
</html>