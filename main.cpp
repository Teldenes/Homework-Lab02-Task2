#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;

class Item
{
 public:

    Item (string n, float p, char v, int a)
     {
      name=n;
      nprice=p;
      VAT=v;
      amount=a;
     }

    string get_name()
     {
      return name;
     }

    int get_name_len()
     {
      return name.size();
     }

    float get_price()
     {
      return nprice;
     }

    char get_taxed()
     {
      return VAT;
     }

    int get_amount()
     {
      return amount;
     }


 private:

  string name;
  float nprice;
  char VAT;
  int amount;
};

class Invoice
{
 public:

    Invoice (long long s, long long b)
     {
      sNIP=s;
      bNIP=b;
     }

    void add_item (Item item)
     {
      Index.emplace_back(item);
     }

    void print_invoice ()
     {
      cout<<"------------------VAT invoice------------------"<<endl
          <<"==============================================="
          <<endl<<"Seller: "<<sNIP<<"      Buyer: "<<bNIP<<endl
          <<endl<<"                  c.j. VAT   il.    net   total"<<endl;

      float nsum=0,sum=0;

      for(auto it=Index.begin(); it != Index.end(); it++)
      {
       int it2=1;
       int l = (*it).get_name_len();

       cout<<it2<<". "<<(*it).get_name();
       for(auto it=1;it <= (13-l) ;it++ )
        {
         cout<<" ";
        }
       cout<<"| "<<(*it).get_price()<<"  "<<(*it).get_taxed()<<" | ";
       if((*it).get_amount() <= 9)
        {
         cout<<"  ";
        }
       else if ((*it).get_amount() <= 99)
        {
         cout<<" ";
        }
       cout<<(*it).get_amount()<<" | ";
       if(((*it).get_price()*(*it).get_amount()) < 10)
        {
         cout<<" ";
        }
       cout<<fixed;
       cout<<setprecision(2);
       cout<<((*it).get_price()*(*it).get_amount())<<" | ";
       nsum+=(*it).get_price()*(*it).get_amount();


       float total;
       if((*it).get_taxed() == 'A')
        {
         total = (*it).get_price()*(*it).get_amount()*1.23;
        }
       else if((*it).get_taxed() == 'B')
        {
         total = (*it).get_price()*(*it).get_amount()*1.08;
        }
       else
        {
         total = (*it).get_price()*(*it).get_amount();
        }
       if(total < 10)
        {
         cout<<" ";
        }
       cout<<total<<endl;
       sum+=total;
      it2++;
      }

      cout<<endl<<endl<<"------------------------------------ TOTAL ----"<<endl
          <<"                                  "<<nsum<<" | "<<sum<<endl;
     }

    friend ostream &operator<<(ostream &out, Invoice &rhs)
    {
     rhs.print_invoice();
    }



 private:
  long long sNIP, bNIP;
  vector<Item> Index;
};



int main()
{
    Invoice inv(7770003699, 1123456789);
    inv.add_item(Item("M3 screw", 0.37, 'A', 100));
    inv.add_item(Item("2 mm drill", 2.54, 'B', 2));
    std::cout << inv << std::endl;
//    inv.print_invoice();
}
