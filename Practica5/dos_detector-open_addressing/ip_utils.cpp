/**
 * @file ip_utils.cpp
 */

#include <algorithm>
#include "ip_utils.hpp"

std::uint64_t
IpToInt::operator() (const IP& ip) const
{
    std::uint64_t ret_val = 0l;
    //TODO
    //Remenber: casting to 64 bits unsigned integer to do not loss bits.
    //Hint: mult by 2^n means shift to left n bits.
    ret_val=(static_cast<uint64_t>(ip.bytes[0])<<24) + (static_cast<uint64_t>(ip.bytes[1])<<16) + (static_cast<uint64_t>(ip.bytes[2])<<8) + (static_cast<uint64_t>(ip.bytes[3]));
    //
    return ret_val;
}

std::ostream&
operator<< (std::ostream& out, const IP& ip)
{
    //TODO
    //Remenber: we want to output the assci code, not the char.
    out << static_cast<int>(ip.bytes[0]) << '.' << static_cast<int>(ip.bytes[1]) << '.' << static_cast<int>(ip.bytes[2]) << '.' << static_cast<int>(ip.bytes[3]);
    //
    return out;
}

std::istream&
operator>>(std::istream& in, IP& ip) noexcept(false)
{
    //TODO
    //Hint: you can use a std::istringstream to convert from text to uint8_t.
    //Hint: you can use the std::replace algorithm to replace '.' by ' '.
    //Remenber: if a wrong format is detected, throw an runtime_error exception.
    std::string text;
     in >> text;
     if(in){
         std::replace(text.begin(), text.end(), '.', ' ');
         std::istringstream in_(text);

         size_t v[4];
         in_ >> v[0] >> v[1] >> v[2] >> v[3];

         if(in_){
             for(size_t i=0; i<4; i++){
                 if(v[i]<256){
                    ip.bytes[i] = static_cast<uint8_t>(v[i]);
                 }
                 else{
                    throw std::runtime_error("Ip: wrong input format.");
                 }
             }
         }
         else{
             throw std::runtime_error("Ip: wrong input format.");
         }
     }
    //
    return in;
}

IpToInt::Ref
IpToInt::create()
{
    return std::make_shared<IpToInt>();
}
