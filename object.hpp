
class Object {
  private: 
    float x;
    float y;
  public:
    Object(float x, float y) : x(x), y(y) {}
    void moveTo(float x, float y);
};

class StaticObject {
  public:
    float x;
    float y;
  
};
