#ifndef __PLANT_H__
#define __PLANT_H__
#include <cstring>

class Plant{
    char species[101];
    char color[31];
    unsigned id;

    void copy(const Plant& other) {
        this->id = other.id;
        strcpy(this->species, other.species);
        strcpy(this->color, other.color);
    }

    public:
    Plant(const char species[], const char color[], const unsigned& id): id(id) {
        strcpy(this->species, species);
        strcpy(this->color, color);
    }

    Plant(const Plant& other) {
        copy(other);
    }

    Plant& operator=(const Plant& other) {
        if (this != &other) {
            copy(other);
        }

        return *this;
    }

    void serialize(std::ostream& os) const {
        os.write((char*)&spicies, sizeof(spicies));
        os.write((char*)&color, sizeof(color));
        os.write((char*)&id, sizeof(id));
    }

    void deserialize(std::istream& is) {
        is.read((char*)&spicies, sizeof(spicies));
        is.read((char*)&color, sizeof(color));
        is.read((char*)&id, sizeof(id));
    }

    void serialize_at(std::ostream &os, std::size_t pos) const {
        os.seekg(pos * (sizeof(spicies) + sizeof(color) + sizeof(id)), std::ios::beg);
        serialize(os);
    }

    void deserialize_at(std::istream &is, std::size_t pos) {
        is.seekp(pos * (sizeof(spicies) + sizeof(color) + sizeof(id)), std::ios::beg);
        deserialize(is);
    }
};

#endif // __PLANT_H__