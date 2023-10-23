#include "Member.hpp"

Member::Member(std::string id, std::string name, std::string phone, std::string email, std::string profileURL)
{
    this->id = id;
    this->name = name;
    this->phone = phone;
    this->email = email;
    this->profileURL = profileURL;
    this->valid=true;
}

Member::Member()
{
    this->valid=false;
}

std::string Member::getId() const
{
    return this->id;
}
bool Member::is_valid() const{
    return this->valid;
}
bool operator==(const Member &a, const Member &b)
{
    return (a.getId() == b.getId());
}