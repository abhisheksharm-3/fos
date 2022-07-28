

#include <iostream>
#include <fstream>
using namespace std;

int main()
{

  // Storing list of foods in string type array "fmenu"
  string fmenu[25] =
      {

          "Burger",
          "Coke",
          "Cold Coffee",
          "Pizza",
          "Spaghetti",
          "French Fries",
          "Momos",
          "Ice Cream",
          "Rolls",
          "Red Sauce Pasta"

      };

  // Storing prices of foods in integer type array "price"
  int price[25] =
      {

          60,
          40,
          99,
          499,
          249,
          80,
          150,
          100,
          149,
          349

      };

  // Storing payment methods in string type array "payment"
  string payment[25] =
      {

          "UPI",
          "Credit/Debit Card",
          "Zomato"

      };

  int order, quantity, cpayment, cardno, expiry;
  string name, contact, delivery, paymentnum, transid, namec;

  cout << "\t\t\t LAXMI FOOD CORNER\n\n"
       << endl;
  cout << "Our Mouth-Watering Food Menu - \n"
       << endl;

  for (int i = 0; i < 10; i++)
  {

    // Showing food menu to customer
    cout << i + 1 << ". " << fmenu[i] << endl;
  }

  cout << "\nSelect the food you want to order : ";

  // Taking order from customer
  cin >> order;

  cout << "\nYou have selected " << fmenu[order - 1] << endl;

  cout << "\nEnter Quantity : ";

  // Taking quantity of food
  cin >> quantity;
  srand(time(0));
  int orderno = rand();

  cout << "\n\n\t\t\tORDER DELIVERY DETAILS\n\n";

  // Taking delivery details from customer
  cout << "Enter Your Name : ";
  cin >> name;
  cout << "Enter Contact Number : ";
  cin >> contact;
  cout << "Enter Delivery Address : ";
  cin >> delivery;

  cout << "\n\n\t\t\tYOUR BILL\n\n";

  // Storing the total amount into the integer type variable "total"
  int total = price[order - 1] * quantity;

  // Showing bill with customer details
  cout << fmenu[order - 1] << " * " << quantity << "\t\t\t" << price[order - 1] << " * " << quantity << endl;
  cout << "\n------------------------------------------------------------\n";
  cout << "Total"
       << "\t\t - \t\t"
       << "Rs." << total << "\n"
       << endl;
  cout << name << endl;
  cout << contact << endl;
  cout << delivery << endl;
  if (quantity > 5)
  {
    cout << "Estimated delivery time : 25 minutes" << endl;
  }
  else
  {
    cout << "Estimated delivery time : 15 minutes" << endl;
  }

  cout << "Order No.:" << orderno << endl;

  float disc = (float)total - ((float)(total * 15) / 100);

  cout << "\n\n\t\t\tPAYMENT INFORMATION\n\n";
  cout << "We Accept - \n\n";
here:
  for (int i = 0; i < 3; i++)
  {

    // Showing payment options to customer
    cout << i + 1 << ". " << payment[i] << endl;
  }

  cout << "\nSelect your desired payment method : ";

  // Taking input from customer
  cin >> cpayment;

  switch (cpayment)
  {
  case 1:
    cout << "Our UPI VPA is: laxmifoodcorner@apl";
    break;
  case 2:
    cout << "Enter your Card Number: ";
    cin >> cardno;
    cout << endl
         << "Enter Expiry (MMYY): ";
    cin >> expiry;
    cout << endl
         << "Enter Name on the card: ";
    cin >> namec;
    break;
  case 3:

    cout << "Zomato Discount - 15%. Amount to be paid after discount: " << disc << endl;
    cout << "Enter Zomato transaction number: ";
    cin >> transid;
    break;

  default:
    cout << "Enter valid Payment Option" << endl;
    goto here;
    break;
  }

  if (cpayment == 1 && total > 249)
  {

    // Customers will get discount when orders more than Rs. 249 using UPI
    cout << "\nYou are eligible for 25% cashback" << endl;
    cout << "\nCongratulations! You have received Rs." << (float)total * 25 / 100 << " as cashback from  LAXMI FOOD CORNER" << endl;
  }

  else if (total > 666)
  {

    // Customers will get discount when orders more than Rs. 666
    cout << "\nYou are eligible for an offer" << endl;
    cout << "\nCongratulations! You have received Rs." << (float)total * 6 / 100 << " as cashback from SNACK BAR" << endl;
  }

  cout << "\nThank you for choosing us. \nENJOY YOUR SNACK! :)\n";
  ofstream ofdata("orderfile");
  ofdata << name << "\n"
         << contact << "\n"
         << delivery << "\n"
         << orderno << "\n"
         << cpayment << "\n"
         << cardno << "\n"
         << expiry << "\n"
         << namec << "\n"
         << transid;

  return 0;
}
