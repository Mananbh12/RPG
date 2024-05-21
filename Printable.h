#ifndef CLASS_PRINTABLE
#define CLASS_PRINTABLE
    #include <iostream>

    class Printable{
    public:
        virtual void to_stream(std::ostream&) const = 0;
        virtual ~Printable(){};
    };

std::ostream& operator<<(std::ostream& o, const Printable& p){
    p.to_stream(o);
    return o;
}

#endif
