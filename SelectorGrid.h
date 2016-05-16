#ifndef SELECTORGRID_H
#define SELECTORGRID_H

#include <iostream>

template <class T> class SelectorGrid {
private:
    int x;
    int y;
    int width;
    int height;
    SelectorGrid* upward;
    SelectorGrid* downward;
    SelectorGrid* leftward;
    SelectorGrid* rightward;
    T* subject;
public:
    SelectorGrid(T*);

    //mutators
    void setXPos(int);
    void setYPos(int);
    void setWidth(int);
    void setHeight(int);

    void setUpward(SelectorGrid<T>*);
    void setDownward(SelectorGrid<T>*);
    void setLeftward(SelectorGrid<T>*);
    void setRightward(SelectorGrid<T>*);
    void setSubject(T*);

    //accessors
    int getXPos();
    int getYPos();
    int getWidth();
    int getHeight();

    SelectorGrid* getUpward();
    SelectorGrid* getDownward();
    SelectorGrid* getLeftward();
    SelectorGrid* getRightward();
    T* getSubject();
};

template <class T> SelectorGrid<T>::SelectorGrid(T* newSubject) {
    upward == NULL;
    downward == NULL;
    leftward == NULL;
    rightward == NULL;

    subject = newSubject;
}

//mutators
template <class T> void SelectorGrid<T>::setXPos(int newPos) { x = newPos; }

template <class T> void SelectorGrid<T>::setYPos(int newPos) { y = newPos; }

template <class T> void SelectorGrid<T>::setWidth(int newWidth) { width = newWidth; }

template <class T> void SelectorGrid<T>::setHeight(int newHeight) { height = newHeight; }

template <class T> void SelectorGrid<T>::setUpward(SelectorGrid<T>* newUp) { upward = newUp; }

template <class T> void SelectorGrid<T>::setDownward(SelectorGrid<T>* newDown) { downward = newDown; }

template <class T> void SelectorGrid<T>::setLeftward(SelectorGrid<T>* newLeft) { leftward = newLeft; }

template <class T> void SelectorGrid<T>::setRightward(SelectorGrid<T>* newRight) { rightward = newRight; }

template <class T> void SelectorGrid<T>::setSubject(T* newSubject) { subject = newSubject; }

//accessors
template <class T> int SelectorGrid<T>::getXPos() { return x; }

template <class T> int SelectorGrid<T>::getYPos() { return y; }

template <class T> int SelectorGrid<T>::getWidth() { return width; }

template <class T> int SelectorGrid<T>::getHeight() { return height; }

template <class T> SelectorGrid<T>* SelectorGrid<T>::getUpward() { return upward; }

template <class T> SelectorGrid<T>* SelectorGrid<T>::getDownward() { return downward; }

template <class T> SelectorGrid<T>* SelectorGrid<T>::getLeftward() { return leftward; }

template <class T> SelectorGrid<T>* SelectorGrid<T>::getRightward() { return rightward; }

template <class T> T* SelectorGrid<T>::getSubject() { return subject; }

#endif // SELECTORGRID_H
