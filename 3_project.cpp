#include <iostream>
#include <string>

 namespace InfiniteArithmetic
   {
      using namespace std;

      class Integer
        {
           private:
             string str;
             int sign = 0;
             friend class Float;
           public: 

           void print()
             {
                cout<<str<<endl;
             }

           void parse(string& str)
             {
                if(str[0] == '0')
                  {
                     while(str[0] == '0')
                          {
                            str.erase(0,1);
                          }
                  }

                if(str[0] == '-')
                  {
                     while(str[1] == '0')
                          {
                            str.erase(1,1);
                          }
                  }

             }

         Integer(string s)
                {
                  str = s; 

                  if(s[0] == '-')
                    {
                       sign = 1;
                    }
                }


        
          Integer operator+(Integer b)
            {
                if(sign == 0&&b.sign == 0)
                  {
                    Integer dummy =*this;

                    if (dummy.str.size()<b.str.size())
                       {
                         Integer hold("9");
                         hold = dummy;
                         dummy = b;
                         b = hold;
                       }

                    int num = b.str.size();

                    for(int i = 0;i<dummy.str.size()-num;i++)
                       {
                          b.str.insert(0,1,'0');
                       }                        //now both are of equal size

                    string c(b.str.size()+1,'0');
            

                    for(int i = 1;i<=dummy.str.size();i++)
                       {
                         c[b.str.size()-i+1] = (dummy.str[b.str.size()-i] + b.str[b.str.size()-i] - '0');
                       }

                    for(int i = 0;i<=dummy.str.size()-1;i++)
                       {
                         if(c[b.str.size()-i]>=10+'0')
                           {
                             c[b.str.size()-i]-=(10);
                             c[b.str.size()-i-1]+=1;
                           }
                       }

                    parse(c);

                    return Integer (c);

                  }

                if(sign == 0&&b.sign == 1)
                  {
                    b.str.erase(0,1);b.sign = 0;
                    Integer dummy =*this;
                    return dummy-b;
                  }

                if(sign == 1&&b.sign == 0)
                  {
                    Integer dummy =*this;
                    dummy.str.erase(0,1);dummy.sign = 0;
                    return b-dummy;
                  }

                if(sign == 1&&b.sign == 1)
                  {
                    Integer dummy =*this;
                    dummy.str.erase(0,1);dummy.sign = 0;
                    b.str.erase(0,1);b.sign = 0;
                    Integer t = b+dummy;
                    t.str.insert(0,1,'-');
                    return t;
                  }

                return Integer("0");

            }



          Integer operator-(Integer b)
            {
               if(sign == 0 && b.sign == 0)
                 {               
                   int minus_indicator = 0;
                   Integer dummy = *this;

                   if (dummy.str.size() < b.str.size())
                      {
                        Integer hold("9");hold = dummy;
                        dummy = b;
                        minus_indicator = 1;
                        b = hold;
                      }

                   int num = b.str.size();

                   for(int i = 0 ; i < dummy.str.size()-num ; i++)
                      {
                        b.str.insert(0,1,'0');
                      }

                     string c(b.str.size()+1,'\0');

                   for(int i = 1 ; i <= dummy.str.size() ; i++)
                      {
                
                       c[b.str.size()-i+1] = char (int(dummy.str[b.str.size()-i]) - int(b.str[b.str.size()-i]) ) ;
                 
                      }
                
                   for(int i = 0 ; i < b.str.size() ; i++)
                      {
                        if(c[b.str.size()-i]<0)
                          {
                            c[b.str.size()-i-1]-=1;
                            c[b.str.size()-i]+=10;
                          }
                      }

                   if(c[0] == -1)
                     {
                        for(int i = 0; i <= dummy.str.size() ; i++)
                           {
                             c[i] =-c[i];
                           }

                        for(int i = 0;i<b.str.size();i++)
                           {
                              if(c[b.str.size()-i]<0)
                                {
                                   c[b.str.size()-i-1]-=1;
                                   c[b.str.size()-i] = c[b.str.size()-i]+10;
                                }
                           }

                        c.insert(0,1,'-'-'0');
                     }

                   for(int i = 0;i<=c.size();i++)
                      {
                        c[i] = c[i]+'0';
                      }

                   if(minus_indicator == 1)
                     {
                       c.insert(0,1,'-');
                     }

                   parse(c);
                   Integer result = Integer(c);

                   return result;

                 }



               if(sign == 1&&b.sign == 0)
                 {
                   Integer dummy=*this;
                   dummy.str.erase(0,1);dummy.sign=0;
                   Integer t = dummy+b;
                   t.str.insert(0,1,'-');t.sign = 1;
                   return t;
                 }
            
               if(sign == 0&&b.sign == 1)
                 {
                   b.str.erase(0,1);b.sign = 0;
                   return *this+b;
                 }
            
               if(sign == 1&&b.sign == 1)
                 {
                    Integer dummy =*this;
                    dummy.str.erase(0,1);dummy.sign = 0;
                    b.str.erase(0,1);b.sign = 0;
                    return Integer(b-dummy);
                 }

              return Integer("0");

            }
        

        
          Integer operator*(Integer b)
            {
               if(sign == 0&&b.sign == 0)
                 {
                   Integer dummy =*this;Integer product("0");
                   for(int i = 0;i<b.str.size();i++)
                      {
                        for (int j = 0;j<b.str[b.str.size()-i-1]-'0';j++)
                            {  
                               product = product+dummy;
                            }

                        dummy.str.push_back('0');                 
                      }

                      return product;

                 }

               if(sign == 1&&b.sign == 0)
                 {
                    Integer dummy =*this;
                    dummy.str.erase(0,1);dummy.sign = 0;
                    Integer t = dummy*b;
                    t.str.insert(0,1,'-');t.sign = 1;
                    return t;
                 }

               if(sign == 1&&b.sign == 1)
                 {
                    Integer dummy =*this;
                    dummy.str.erase(0,1);dummy.sign = 0;
                    b.str.erase(0,1);b.sign = 0;
                    Integer t = dummy*b;
            
                     return t;
                 }

               if(sign == 0&& b.sign == 1)
                 {
                   Integer dummy =*this;
                   b.str.erase(0,1);b.sign = 0;
                   Integer t = dummy*b;
                   t.str.insert(0,1,'-');t.sign = 1;

                   return t;
                 }

                return Integer("0");

            }       


         int operator>(Integer b)
          {
             if(sign == 0&&b.sign == 0)
               {
                 parse(b.str);Integer dummy =*this;
                 parse(dummy.str);

                 if(dummy.str.size()>b.str.size())
                   {
                     return 1;
                   }

                 else if(b.str.size()>dummy.str.size())
                        {
                          return 0;
                        }

                 else
                     {
                       for(int i=0;i<dummy.str.size();i++)
                          {
                             if(dummy.str[i]>b.str[i])
                               {
                                  return 1;
                               }

                             else if(dummy.str[i]<b.str[i])
                                    {
                                       return 0;
                                    }
                          }
                     }
               }
        
             return 0;

          }



          Integer operator/(Integer b)
            {
              if(sign == 0&&b.sign == 0)
                {
                  Integer dummy=*this;
                  string result;
                  if(b>dummy)
                    {
                       return Integer("0");
                    }
            
                  else {
                         parse(b.str); 
                         parse(dummy.str);
                         string com=dummy.str.substr(0,b.str.size());
    
                         for(int i = 0;i<=dummy.str.size()-b.str.size();i++)
                            {
                              for(int j = 0;j<10;j++)
                                 {
                                   char ch = char(j+'0');
                                   string s;
                                   s+=ch;

                                   if((b)>Integer(com)-Integer(s)*b)
                                     {
                          
                                       result.push_back(ch);
                            
                                       Integer dcom = (Integer(com)-Integer(s)*b);

                                       if(i != dummy.str.size()-b.str.size())
                                         {
                                           dcom.str.push_back(dummy.str[b.str.size()+i]);
                                           com = dcom.str;
                            
                                         }
  
                                       break;

                                     }

                                 }           
                            }
            
                         return Integer(result);

                        }
                }

                  if(sign==1&&b.sign==0)
                    {
                      Integer dummy=*this;
                      dummy.str.erase(0,1);
                      dummy.sign=0;
                      Integer t= dummy/b;
                      t.str.insert(0,1,'-');
                      t.sign=1;

                      return t;
                    }

                if(sign==0&&b.sign==1)
                  {
                    Integer dummy=*this;
                    b.str.erase(0,1);
                    b.sign=0;
                    Integer t= dummy/b;
                    t.str.insert(0,1,'-');
                    t.sign=1;
                    
                    return t;

                  }

                if(sign==1&&b.sign==1)
                  {
                    Integer dummy=*this;
                    dummy.str.erase(0,1);
                    dummy.sign=0;
                    b.str.erase(0,1);
                    b.sign=0;
                    Integer t=dummy/b;

                    return t;
                  }

            }
            
        };





      class Float
        {
           public:
           string str;
           int sign = 0;
           size_t point_position = -1;
           int pa,pb;

           Float(string s)
                {
                  str = s;

                  if(s[0] == '-')
                    {
                      sign = 1;
                    }

                  point_position = str.find('.');

                  if(point_position == string::npos)
                    {
                        str.push_back('.');
                        point_position=str.size()-1;
                    }
                  pb = point_position;
                  pa = str.size()-point_position-1;
                }

           Float()
                {
                  str = "0.";
                  point_position = 1;sign = 0;pa = 0;pb = 1;
                }



           Float operator+(Float b)
              {
                string c;

                if(sign == 0&&b.sign == 0)
                  {
                    Float dummy = *this;

                    if(dummy.pb<b.pb)
                      {
                        for(int i = 0;i<b.pb-dummy.pb;i++)
                           {
                              dummy.str.insert(0,1,'0');
                           }
                      }

                    if(dummy.pb>b.pb)
                      {
                        for(int i = 0;i<dummy.pb-b.pb;i++)
                           {
                             b.str.insert(0,1,'0');
                           }
                      }
                
                    if(dummy.pa<b.pa)
                      {
                        for(int i = 0;i<b.pa-dummy.pa;i++)
                           {
                             dummy.str.push_back('0');
                           }
                      }

                    if(dummy.pa>b.pa)
                      {
                       for(int i = 0;i<dummy.pa-b.pa;i++)
                          {
                            b.str.push_back('0');
                          }
                      }

                    dummy = Float(dummy.str);
                    b = Float(b.str); 

                    if(dummy.str.size() == b.str.size())
                      {
                
                      }

                    int y = dummy.str.size()-1-dummy.point_position;;
                    dummy.str.erase(dummy.point_position,1);
                    b.str.erase(b.point_position,1);
                    Integer add = Integer(dummy.str)+Integer(b.str);
            
                    add.str.insert(add.str.size()-y,1,'.');
                    c = add.str;
                    return Float(c);

                  }

                if(sign == 0&&b.sign == 1)
                  {
                     Float dummy =*this;
                     b.str.erase(0,1);b=Float(b.str);
                     return dummy-b;
                  }

                if(sign == 1 &&b.sign == 0)
                  {
                     Float dummy =*this;
                     dummy.str.erase(0,1);dummy = Float(dummy.str);
                     return b-dummy;
                  }

                if(sign == 1&&b.sign == 1)
                  {
                    Float dummy =*this;
                    dummy.str.erase(0,1);dummy = Float(dummy.str);
                    b.str.erase(0,1);b = Float(b.str);
                    Float t = dummy+b;
                    t.str.insert(0,1,'-');
                    
                    return Float(t.str);

                  }

                return Float("0");
              }

           void print()
             {
               cout<<str<<endl;
             }



           Float operator-(Float b)
              {
                string c;

                if(sign == 0&&b.sign == 0)
                  {
                    Float dummy = *this;

                    if(dummy.pb<b.pb)
                      {
                        for(int i = 0;i<b.pb-dummy.pb;i++)
                           {
                             dummy.str.insert(0,1,'0');
                           }
                      }

                    if(dummy.pb>b.pb) 
                      {
                        for(int i = 0;i<dummy.pb-b.pb;i++)
                           {
                             b.str.insert(0,1,'0');
                           }
                      }

                    if(dummy.pa<b.pa)
                      {
                        for(int i = 0;i<b.pa-dummy.pa;i++)
                           {
                             dummy.str.push_back('0');
                           }
                      }

                    if(dummy.pa>b.pa)
                      {
                       for(int i = 0;i<dummy.pa-b.pa;i++)
                          {
                            b.str.push_back('0');
                          }
                      }

                    dummy = Float(dummy.str);
                    b = Float(b.str);

                    if(dummy.str.size() == b.str.size())
                      {
            
                      }

                    int y = dummy.str.size()-1-dummy.point_position;;
                    dummy.str.erase(dummy.point_position,1);
                    b.str.erase(b.point_position,1);
                    Integer sub = Integer(dummy.str)-Integer(b.str);
            
                    sub.str.insert(sub.str.size()-y,1,'.');
                    c = sub.str;

                    return Float(c);

                  }

                if(sign == 0&&b.sign == 1)
                  {
                    Float dummy =*this;
                    b.str.erase(0,1);
                    b = Float(b.str);
                    return dummy+b;
                  }

                if(sign == 1&&b.sign == 0)
                  {
                    Float dummy =*this;
                    dummy.str.erase(0,1);
                    dummy = Float(dummy.str);
                    Float t = dummy+b;
                    t.str.insert(0,1,'-');

                    return Float(t.str);
                  }

                if(sign == 1&&b.sign == 1)
                  {
                    Float dummy =*this;
                    dummy.str.erase(0,1);
                    dummy = Float(dummy.str);
                    b.str.erase(0,1);
                    b = Float(b.str); 

                    return b-dummy;

                  }

                return Float("0");
              }



           Float operator*(Float b)
              {
                string c;
                if(sign == 0&&b.sign == 0)
                  {
                    Float dummy =*this;
                    int y1 = dummy.str.size()-1-dummy.point_position;
                    int y2 = b.str.size()-1-b.point_position;
                    dummy.str.erase(dummy.point_position,1);
                    b.str.erase(b.point_position,1);
                    Integer mul = Integer(dummy.str)*Integer(b.str);
                    a:

                    if(mul.str.size()>y1+y2)
                      {
                         mul.str.insert(mul.str.size()-y1-y2,1,'.');
                      }

                    else 
                         {
                           mul.str.insert(0,1,'0');
                           goto a;
                         }

                    c=mul.str;

                    return Float(c);

                  }

                if(sign == 1&&b.sign == 0)
                  {
                    Float dummy =*this;
                    dummy.str.erase(0,1);
                    dummy = Float(dummy.str);
                    Float t = dummy*b;
                    t.str.insert(0,1,'-');
                    
                    return(Float(t.str));
                  }

                if(sign == 0&&b.sign == 1)
                  { 
                    Float dummy =*this;
                    b.str.erase(0,1);
                    b = Float(b.str);
                    Float t = dummy*b;
                    t.str.insert(0,1,'-');

                    return Float(t.str);
                  }

                if(sign == 1&&b.sign == 1)
                  {
                    Float dummy =*this;
                    dummy.str.erase(0,1);
                    dummy = Float(dummy.str);
                    b.str.erase(0,1);
                    b = Float(b.str);
                    Float t = dummy*b;

                    return t;
                  }

                return Float("0");

              }



           Float operator/(Float b)
              {
                 string c;
                 if(sign==0&&b.sign==0)
                   {
                     Float dummy=*this;
                     int y1=dummy.str.size()-1-dummy.point_position;
                     int y2=b.str.size()-1-b.point_position;
                     dummy.str.erase(dummy.point_position,1);
                     b.str.erase(b.point_position,1);

                     for(int i=0;i<1000;i++)
                        {
                           dummy.str.push_back('0');
                        }

                   

                     Integer c=Integer (dummy.str)/Integer(b.str);
                     c.str.insert(c.str.size()-1000-y1+y2,1,'.');
                     

                     return Float(c.str);
                 
                    }
            
                 if(sign==0&&b.sign==1)
                   {
                      Float dummy=*this;
                      b.str.erase(0,1);
                      b=Float(b.str);
                      Float t=dummy/b;
                      t.str.insert(0,1,'-');
                      
                      return(Float(t.str));

                    }

                 if(sign==1&&b.sign==0)
                   {
                      Float dummy=*this;
                      dummy.str.erase(0,1);
                      dummy=Float(dummy.str);
                      Float t=dummy/b;
                      t.str.insert(0,1,'-');
                      
                      return(Float(t.str));

                   }

                 if(sign==1&&b.sign==1)
                   {
                      Float dummy=*this;
                      dummy.str.erase(0,1);
                      dummy=Float(dummy.str);
                      b.str.erase(0,1);
                      b=Float(b.str);
                      Float t=dummy/b;

                      return t;

                   }
                  
                  return Float("0");
        }};

         
    } 
 

int main(int argc, char* argv[])
       {
         using namespace InfiniteArithmetic; 
         std::string s1=argv[1];
         std::string s2=argv[2];
         std::string s3=argv[3];
         std::string s4=argv[4];

            if(s1=="int")
            {
            Integer a=Integer(s3);
            Integer b=Integer(s4);

            if(s2=="add") 
              {
                Integer d=a+b;
                d.print();
              }

            if(s2=="sub")
              {
                Integer d=a-b;
                d.print();
              }
            
            if(s2=="mul")
              {
                Integer d=a*b;
                d.print();
              }
            
            if(s2=="div")
              {
                Integer d=a/b;
                d.print();
              }

          }


         if(s1=="float")
           {
              Float a=Float(s3);
              Float b=Float(s4);
              
              if(s2=="add")
                {
                   Float d=a+b;
                   d.print();
                }

              if(s2=="sub")
                {
                   Float d=a-b;
                   d.print();
                }

              if(s2=="mul")
                {
                  Float d=a*b;
                  d.print();
                }

              if(s2=="div")
                {
                  Float d=a/b;
                  d.print();
                }
           } 

          return 0;
        }
