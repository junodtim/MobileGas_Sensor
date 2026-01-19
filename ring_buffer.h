#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <Arduino.h>

// Define SensorData struct once here
struct SensorData {
  int mq2;
  int mq135;
  unsigned long timestamp;
};

// Template ring buffer class
template <typename T, size_t Size>
class RingBuffer {
public:
  RingBuffer() : head(0), tail(0), count(0) {}

  void push(const T& item) {
    buffer[head] = item;
    head = (head + 1) % Size;
    if (count < Size) {
      ++count;
    } else {
      tail = (tail + 1) % Size; // Overwrite oldest
    }
  }

  bool isEmpty() const {
    return count == 0;
  }

  T getLatest() const {
    if (isEmpty()) {
      return T(); // Return default if empty
    }
    size_t latestIndex = (head == 0) ? Size - 1 : head - 1;
    return buffer[latestIndex];
  }

private:
  T buffer[Size];
  size_t head;
  size_t tail;
  size_t count;
};

#endif // RING_BUFFER_H