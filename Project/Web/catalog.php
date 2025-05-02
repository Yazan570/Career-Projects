<!DOCTYPE html>
<?php
session_start();
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
                <li><a href="Sign_up.php">Sign up</a></li>
                <li><a href="order-confirmation.php">Order Confirmation</a></li>
            </ul>
        </nav>
    </header>
    <main>
        <section id="product-catalog">
            <h2>Product Catalog</h2>
            <!-- Product catalog will be dynamically loaded here -->
        </section>
        <div class="items">
            <div class="boxItem">
            <a href="item1.php"><img src="image.png" height="200px" width="150px"class="i1 pic"></a>
            <span class="smallInformation">3lawi cotton T-shirt, relaxed fit and comfortable for summer vibes.</span>
        </div>

        <div class="boxItem">
            <a href="item2.php"><img src="pants2.png" height="200px" width="150px"class="i2 pic"></a>
            <span class="smallInformation">3lawi cargo pants, 2 extra pockets as you wish.</span>
        </div>

        <div class="boxItem">
            <a href="item3.php"><img src="jacket.png" height="200px" width="150px"class="i3 pic"></a>
            <span class="smallInformation">3lawi Leather jacket, warm and comfortable, especially for rainy days.
            </span>
        </div>

        <div class="boxItem">
            <a href="item4.php"><img src="shirt.png" height="200px" width="150px"class="i4 pic"></a>
            <span class="smallInformation">3lawi Shirt, newly designed "glow in the dark" shirt, standard fit.</span>
        </div>

        </div>
    </main>
    <footer>
        <p>&copy; 2024 3LAWI FOR T-SHIRTS. All rights reserved.</p>
    </footer>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script src="scripts.js" defer></script>
</body>
</html>