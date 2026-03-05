#include <cstddef>

template< class T >
T* merge(const T* a, size_t sa, const T* b, size_t sb, T* c) {
  size_t i = 0;
  size_t j = 0;
  size_t k = 0;
  while (i < sa && j < sb){
    c[k++] = (a[i] < b[j]) ? a[i++] : b[j++]; // T::operator<
  }
  while (i < sa) {
    c[k++] = a[i++]; // T::operator=
  }
  while (j < sb) {
    c[k++] = b[j++]; // T::operator=
  }
  return c;
}

// Неявный интерфейс: T::operator<, T::operator=
// Недостатки явного интерфейса: пользователю самому придётся выделять память под функцию
