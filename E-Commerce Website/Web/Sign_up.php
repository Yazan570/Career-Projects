<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Checkout - 3LAWI FOR T-SHIRTS</title>
    <link rel="stylesheet" href="styles.css">
    <script src="script.js"></script>

</head>
<body>
    <header>
        <div class="logo"><img src="logo.png" height="100px"></div>
        <nav class="navbar">
            <ul>
                <li><a href="index.html">Home</a></li>
                <li><a href="catalog.php">Catalog</a></li>
            </ul>
        </nav>
    </header>
    <main>
        <section id="checkout-form">
            <h2>Checkout</h2>
            <form action="sign_up1.php" method="post" onsubmit="return validate(event)">
                <label for="name">Name:</label>
                <input type="text" id="name" name="name" required>
                
                <label for="email">Email:</label>
                <input type="email" id="email" name="email" required>

                <label for="password">Password:</label>
                <input type="password" id="password" name="password" required>

                <label for="number">Phone Number:</label>
                <input type="text" id="number" name="number" required>
                
                <label for="address">Shipping Address:</label>
                <input type="text" id="address" name="address" required>
                
                <button type="submit" id="submit" >Place Order</button>
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