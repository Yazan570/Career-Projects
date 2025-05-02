<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Cart - 3LAWI FOR T-SHIRTS</title>
    <link rel="stylesheet" href="styles.css">
</head>
<style>
    .product {
    border: 1px solid #ccc;
    padding: 10px;
    margin-bottom: 10px;
}
#btn{
    margin-left:50px;

}

</style>
<body>
    <header>
        <div class="logo"><img src="logo.png" height="100px"></div>
        <nav class="navbar">
            <ul>
                <li><a href="index.php">Home</a></li>
                <li><a href="catalog.php">Catalog</a></li>
                <li><a href="cart.php">Cart</a></li>
                <li><a href="order-confirmation.php">Checkout</a></li>
            </ul>
        </nav>
    </header>
    <main>
        <section id="cart">
            <h2>Your Shopping Cart</h2>
            <?php
            session_start();

            if(isset($_SESSION['customer_id'])) {
                $conn = mysqli_connect("localhost", "root", "", "database");

                if(!$conn) {
                    die("Connection failed: " . mysqli_connect_error());
                }

                $customer_id = $_SESSION['customer_id'];
                $sql = "SELECT * FROM cart WHERE customer_id = $customer_id";
                $result = mysqli_query($conn, $sql);

                if(mysqli_num_rows($result) > 0) {
                    while($row = mysqli_fetch_assoc($result)) {
                        echo "<div class='product'>";
                        echo "<p>Product ID: " . $row['product_id'] . "</p>";
                        echo "<p>Color: " . $row['color'] . "</p>";
                        echo "<p>Size: " . $row['size'] . "</p>";
                        echo "</div>";
                    }
                
                } else {
                    echo "<p>Your cart is empty.</p>";
                }

                mysqli_close($conn);
            } else {
                echo "<p>Please log in to view your cart.</p>";
            }
            ?>
          
  <form action="http://localhost/Web/order-confirmation.php" method="GET">
        <button id="btn"type="submit" class="checkout-button">Checkout</button>
    </form>
        </section>
    </main>
    <footer>
        <p>&copy; 2024 3LAWI FOR T-SHIRTS. All rights reserved.</p>
    </footer>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="scripts.js" defer></script>
</body>
</html>
