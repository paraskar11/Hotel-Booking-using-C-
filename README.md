Overview
This project is a simple hotel booking management system implemented in C++. It allows users to book hotel rooms, providing details such as room type, booking dates, guest information, and payment details. The project is designed to run in a console environment, interacting with the user through text-based input and output.

Features
Room Booking: Users can book hotel rooms specifying the room type (AC or Non-AC), booking dates, and the number of guests.
Guest Information: Collects information about the guest, including their name, phone number, and age.
Payment Handling: Calculates the total amount based on the room type and the number of guests. It also collects the card number for payment processing.
Persistence: Booking details are saved to a file (server.txt by default) for later retrieval and reference.
How to Use
Compile: Compile the source code using a C++ compiler. For example, you can use g++:
g++ hotel_booking.cpp -o hotel_booking
Run: Execute the compiled binary:
./a.out

Interaction: Follow the prompts to make bookings, enter guest information, and proceed with payment. Choose options to continue with new records, read existing records, or exit the program.

File Structure
hotel_booking.cpp: The main source code file containing the implementation of the hotel booking system.
server.txt: The text file where booking details are stored.
Future Improvements
User Authentication: Implement user authentication to allow only authorized users to make bookings.
Error Handling: Improve error handling for invalid inputs and edge cases.
GUI Interface: Develop a graphical user interface for a more user-friendly experience.
Database Integration: Replace text file storage with a proper database for better scalability and data management.

Contributors
Abhishek Paraskar


