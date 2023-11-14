#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 
        Node<T>* first;
	int n;


    public:

        ListLinked(){
		n=0;
		first=nullptr;
	}
	-ListLinked(){
		while(first!=nullptr){
			Node<T>* aux = first;
            		first = first->next;
            		delete aux;
        	}
        	n = 0;
	}
	T operator[](int pos) {
        	if (pos < 0 || pos >= n) {
            		throw std::out_of_range("Fuera de rango!");
        	}
        	Node<T>* aux = first;
        	for (int i = 0; i < pos; i++) {
            		aux = aux->next;
        	}
        	return aux->data;
	}
	void insert(int pos, T e) override final{
                    if (n == max){
                            resize(max*2);
                    }

                    if(pos < 0 || pos > n){
                            throw std::out_of_range("Fuera de rango!");
                    }
                    if(empty()){
                            arr = new T[MINSIZE];
                    }
                    for(int i = n; i > pos; i--){
                            arr[i] = arr[0];
                    }
                            arr[pos] = e;
                            n++;
        }


        void append(T e) override final{
                    if (n == max){
                        resize(max*2);
                    }
                    arr[n] = e;
                    n++;
        }
	void prepend(T e) override final{
                    if (n == max ){
                        resize(max*2);
                    }
                    for (int i = n; i > 0; i--){
                        arr[i] = arr[i-1];
                    }
                    arr[0] = e;
                    n++;
        }
	T remove(int pos)override final{
                    if(pos < 0|| pos>= n){
                            throw std::out_of_range("Fuera de rango!");
                    }
                    T el = arr[pos];
                    for(int i = pos; i < n-1; i++){
                            arr[i] = arr[i+1];
                    }
                    n--;
                    return el;
        }
        T get(int pos) override final{
                    if(pos >= 0 && pos < n){
                            return arr[pos-1];
                    }else{
                            throw std::out_of_range("Fuera de rango!");
                    }
        }
        int search(T e) override final {
                        for (int i = 0; i < n; i++) {
                            if (arr[i] == e) {
                                 return i;
                            }
                        }
                        return -1;
        }
        bool empty() override final{
                    return n = 0;
        }

        int size() override final{
                    return n;
        }


