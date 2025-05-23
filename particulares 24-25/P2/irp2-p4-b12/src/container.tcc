 #include <iostream>
 using namespace std;
 
namespace P4{

template <typename U>
std::ostream &operator<<(std::ostream &os, const Container<U> &c){
	if(c.cname != ""){
		os << c.cname << endl;
	}
	for(int i = 0; i < c.items.size(); i++){
		if constexpr (std::is_pointer<U>::value){
			os << *(c.items[i]); // al contenido		
		}
		else{
			os << c.items[i]; // llamo al operador salida
			// directly
		}
		os << endl;
	}
	return os;
}
    
template <typename T>
Container<T>::Container(const std::string& name){
	cname = name;
}

template <typename T>
void Container<T>::set_name(const std::string& name){
	cname = name;
}

template <typename T>
const std::string& Container<T>::get_name() const{
	return cname;	
}

template <typename T> 
void Container<T>::add(const T& item){
	items.push_back(item);
}


template <typename T>
void Container<T>::remove(const T& item){
	for(int i = 0; i< items.size(); i++){
		// 
		if(items[i] == item){
			items.erase(items.begin() + i);
			i--;
		}
	}
	
	// asi no me salto ninguna ^^ 
	for(int i = items.size() - 1; i >= 0; i--){
		if(items[i] == item){
			items.erase(items.begin() + i);
		}	
	}
	
}

template <typename T>
uint16_t Container<T>::find(const T& item) const{
	uint16_t pos = numeric_limits<uint16_t>::max();
	for(uint16_t i = 0; i < items.size() && pos == numeric_limits<uint16_t>::max(); i++){
		if(items[i] == item){
			pos = i;
		}
	}
	return pos;
}

template <typename T>
T& Container<T>::operator[](size_t i){
	return items[i];
}

template <typename T>
size_t Container<T>::size() const{
	return items.size();
}
}


