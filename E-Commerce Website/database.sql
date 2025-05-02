-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 26, 2024 at 01:27 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `database`
--

-- --------------------------------------------------------

--
-- Table structure for table `cart`
--

CREATE TABLE `cart` (
  `cart_id` int(11) NOT NULL,
  `customer_id` int(11) NOT NULL,
  `product_id` int(11) NOT NULL,
  `quantity` int(11) NOT NULL,
  `color` varchar(100) NOT NULL,
  `size` varchar(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `cart`
--

INSERT INTO `cart` (`cart_id`, `customer_id`, `product_id`, `quantity`, `color`, `size`) VALUES
(1, 1, 1, 1, 'Green', 'M'),
(3, 2, 1, 1, 'Green', 'M'),
(8, 2, 1, 1, 'Blue', 'S'),
(9, 2, 1, 1, 'Blue', 'S'),
(10, 2, 1, 1, 'Green', 'S'),
(11, 4, 1, 1, 'Green', 'XL'),
(12, 4, 1, 1, 'Red', 'XS'),
(13, 4, 1, 1, 'Blue', 'XL'),
(22, 5, 1, 1, 'Red', 'XS'),
(23, 5, 1, 1, 'Green', 'M'),
(24, 5, 1, 1, 'Blue', 'M'),
(25, 5, 1, 1, 'Blue', 'M'),
(26, 5, 1, 1, 'White', 'S'),
(27, 6, 1, 1, 'Red', 'S'),
(28, 6, 1, 1, 'Green', 'M'),
(29, 6, 1, 1, 'Red', 'XL');

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE `customer` (
  `name` varchar(70) NOT NULL,
  `id` int(250) NOT NULL,
  `password` varchar(250) NOT NULL,
  `number` varchar(100) NOT NULL,
  `address` varchar(250) NOT NULL,
  `email` varchar(250) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`name`, `id`, `password`, `number`, `address`, `email`) VALUES
('generate', 1, 'A3,l;klewr', 'rwerew', 'rwerewr', 'rwerwer@gmail.com'),
('generate', 2, 'A3,l;klewr', 'rwerew', 'rwerewr', 'rwerwer@gmail.com'),
('wqe', 3, 'Q3werwerwr', '3453453', 'rwerwrw', 'rwerwer@gmail.com'),
('last', 4, 'l;fmldsfA2', '3424234', 'werwer', 'rwerwer@gmail.com'),
('yehea', 5, 'rewrSD3ewqeeq', 'erter', 'er', 'fsd@gmail.com'),
('ewrwerwer', 6, 'wrrwerwerA23', '3453453', 'dsfdsf', 'rwerwer@gmail.com');

-- --------------------------------------------------------

--
-- Table structure for table `products`
--

CREATE TABLE `products` (
  `id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `description` text DEFAULT NULL,
  `price` decimal(10,2) NOT NULL,
  `image` varchar(255) NOT NULL,
  `type` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `products`
--

INSERT INTO `products` (`id`, `name`, `description`, `price`, `image`, `type`) VALUES
(1, '3lawi cotton T-shirt', '3lawi cotton T-shirt, relaxed fit and comfortable for summer vibes.', 25.00, 'image.png', 1),
(2, '3lawi cargo pants', '3lawi cargo pants, 2 extra pockets as you wish.', 35.00, 'pants2.png', 2),
(3, '3lawi Leather jacket', '3lawi Leather jacket, warm and comfortable, especially for rainy days.', 50.00, 'jacket.png', 3),
(4, '3lawi Shirt', '3lawi Shirt, newly designed \"glow in the dark\" shirt, standard fit.', 20.00, 'shirt.png', 1);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `cart`
--
ALTER TABLE `cart`
  ADD PRIMARY KEY (`cart_id`);

--
-- Indexes for table `customer`
--
ALTER TABLE `customer`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `products`
--
ALTER TABLE `products`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `cart`
--
ALTER TABLE `cart`
  MODIFY `cart_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=30;

--
-- AUTO_INCREMENT for table `customer`
--
ALTER TABLE `customer`
  MODIFY `id` int(250) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `products`
--
ALTER TABLE `products`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `cart`
--
ALTER TABLE `cart`
  ADD CONSTRAINT `cart_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `customer` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
