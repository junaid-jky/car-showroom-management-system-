# car-showroom-management-system-

Description

This project implements a Car Showroom Management System using Object-Oriented Programming (OOP) principles, including inheritance, composition, and friend functions/classes. It allows users to manage cars in a showroom, add new cars, sell cars, track total sales, and maintain a customer database. The system is menu-driven and provides an interactive interface for the user to perform various operations.

Features
Car Management: Add, view, and sell cars in the showroom.
Customer Management: Track customers and the cars they purchase.
Total Sales Tracking: Keep a record of total sales made by the showroom.
Interactive Menu: A user-friendly menu-driven system for easy operation.

Key OOP Concepts Implemented:
1. Inheritance: The LuxuryCar class inherits from the Car class, adding luxury features to the car.
2. Composition: The Manager class is composed inside the Showroom class to represent the manager of the showroom.
3. Friend Functions: The showroomInfo function is declared as a friend of the Showroom class to access private members and display detailed showroom information.

Classes:
Car: Represents a car with attributes like model, price, and year.
LuxuryCar: Inherits from the Car class and adds a luxury feature.
Manager: Represents a showroom manager with a name.
Customer: Represents a customer with the name and car model they purchased.
Showroom: Manages the cars and customers in the showroom and tracks total sales.

Usage
1. Add Car: Add a new car to the showroom with details such as model, price, and year.
2. View Cars: Display all cars currently available in the showroom.
3. Sell Car: Sell a car to a customer and remove it from the showroom.
4. View Total Sales: Display the total amount of sales made.
5. View Customers: View all customers and the cars they have purchased.
6. Showroom Info: View the manager's details and total sales.
