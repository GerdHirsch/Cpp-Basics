/*
 * DeadBeef.h
 *
 *  Created on: 18.08.2017
 *      Author: Gerd
 */

#ifndef DEADBEEF_H_
#define DEADBEEF_H_

class MyClass
{
    public:
        MyClass(bool underflow = false, bool overflow  = false)
        :myInt(42)
        {
        	cout << boolalpha;
            cout << "MyClass(underflow: "<<underflow<<" overflow: "<<overflow<<")"<<endl;
            cout << "this:" << hex << this << endl;
            if(underflow)
            {
                unsigned int* p = reinterpret_cast<unsigned int*>(this);
                --p;
                *p = 0xAFFEAFFE;
            }
            if(overflow)
            {
                unsigned int* p = reinterpret_cast<unsigned int*>(this+1);
                *p = 0xAFFEAFFE;
            }
        }
        //versteckt alle anderen new Operatoren
        void* operator new(size_t size)
        {
            cout << "new(size_t " << size << ")" << endl;

            size += 2 * sizeof(unsigned int);
            void* pMem = ::operator new(size);
            *reinterpret_cast<unsigned int*>(pMem) = m_signature;
            char *p = reinterpret_cast<char*>(pMem);
            p += size - sizeof(unsigned int);
            *reinterpret_cast<unsigned int*>(p) = m_signature;
            p = reinterpret_cast<char*>(pMem);
            return ( p + sizeof(unsigned int));
        }
        void operator delete(void* pMem, size_t size)
        {
            cout << "delete(void* " << hex << pMem << ", size_t " << size << ")" << endl;
            //todo hier den anfang und das ende prüfen
            //DEADBEEF
            char* p = reinterpret_cast<char*>(pMem);
            // an das ende Positionieren
            p += size;
            unsigned int* pSignature = reinterpret_cast<unsigned int*>(p);
            if(*pSignature == m_signature)
            {
                cout << "Keine Bereichsueberschreitung: " << hex << *pSignature << endl;
            }else
            {
                cout << "Bereichsueberschreitung: " << hex << *pSignature << endl;
            }

            // an den anfang positionieren
            p = reinterpret_cast<char*>(pMem);
            p -= sizeof(unsigned int);
            pSignature = reinterpret_cast<unsigned int*>(p);
            if(*pSignature == m_signature)
            {
                cout << "Keine Bereichsunterschreitung: " << hex << *pSignature << endl;
            }else
            {
                cout << "Bereichsunterschreitung: " << hex << *pSignature << endl;
            }

            ::delete p;
        }
        virtual ~MyClass()
        {
            cout << "~MyClass() myInt: " << dec << myInt <<endl;
        }
    private:
        static constexpr unsigned int m_signature = 0xDEADBEEF;
        int myInt;
};

#endif /* DEADBEEF_H_ */
