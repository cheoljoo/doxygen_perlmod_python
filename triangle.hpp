/**
 * @brief Triangle class used for triangle manipulations.
@startuml
class Triangle {
        +Triangle()
        +Triangle(const double a, const double b, const double c)
        +Triangle(const Triangle& triangle)
        +scale(const double factor) : Triangle {query}
        +operator=(const Triangle& triangle) : Triangle&
        +isEquilateral() : bool {query}
        +isEquivalent(const Triangle& triangle) : bool {query}
        +isIsosceles() : bool {query}
        +isSimilar(const Triangle& triangle) : bool {query}
        +operator==(const Triangle& triangle) : bool {query}
        +area() : double {query}
        +getArea(int& a, int& b) : double {query}
        +getSideA() : double {query}
        +getSideB() : double {query}
        +getSideC() : double {query}
        -mA : double
        -mB : double
        -mC : double
        +perimeter() : double {query}
        +rotations() : std::vector<Triangle> {query}
}
@enduml

 */
class Triangle
{
public:
    /**
     * Create a new Triangle object of side lengths 1, 1, and 1.
     * @brief Default constructor.
     * @see Triangle(const double a, const double b, const double c)
     * @see Triangle(const Triangle& triangle)
     */
    Triangle();
    /**
     * Create a new Triangle object from side lengths.
     * @brief Constructor.
     * @param [in] a The Length of triangle side a.
     * @param [in] b The Length of triangle side b.
     * @param [in] c The Length of triangle side c.
     * @see Triangle()
     * @see Triangle(const Triangle& triangle)
     */
    Triangle(const double a, const double b, const double c);
    /**
     * Construct a new Triangle object from another Triangle object.
     * @brief Copy constructor.
     * @param triangle Another Triangle object.
     * @see Triangle()
     * @see Triangle(const double a, const double b, const double c)
     */
    Triangle(const Triangle& triangle);

    /**
     * @brief Get the length of side a.
     * @return The length of side a.
     */
    double getSideA() const;

    /**
     * @brief Get the length of side b.
     * @return The length of side b.
     */
    double getSideB() const;

    /**
     * @brief Get the length of side c.
     * @return The length of side c.
     */    
    double getSideC() const;

    /**
     * @brief Get a vector of the Triangle objects whose side lengths have been rotated.
     * @return A vector of Triangle objects.
     */
    std::vector<Triangle> rotations() const;

    /**
     * @brief Assignment overloading.
     * @param triangle Another Triangle object.
     * @return The reference to the current Triangle object.
     */ 
    Triangle& operator=(const Triangle& triangle);
    
    /**
     * @brief Equivalence overloading.
     * @param triangle another Triangle object.
     * @return Whether the two Triangle objects are the same.
     */     
    bool operator==(const Triangle& triangle) const;

    /**
     * @brief Determine if the Triangle object is equivalent to the other.
     * @param triangle Another Triangle object.
     * @return Whether the two Triangle objects are the same.
     */ 
    bool isEquivalent(const Triangle& triangle) const;
    /**
     * @brief Determine if the Triangle object is similar to the other.
     * @param triangle Another Triangle object.
     * @return Whether the two Triangle objects are similar.
     */ 
    bool isSimilar(const Triangle& triangle) const;
    /**
     * @brief Determine if the Triangle object is quilateral.
     * @return Whether the Triangle objects is equilateral.
     */ 
    bool isEquilateral() const;
    /**
     * @brief Determine if the Triangle object is isosceles.
     * @return Whether the Triangle objects is isosceles.
     */ 
    bool isIsosceles() const;

    /**
     * @brief Get the perimeter of the Triangle object.
     * @return The perimeter of the Triangle object.
     */ 
    double perimeter() const;
    /**
     * @brief Get the area of the Triangle object.
     * @return The area of the Triangle object.
     */ 
    double area() const;
    /**
     * @brief Example of get out or in/out parameter
     * @param [in,out] a example of in/out
     * @return The area of the Triangle object.
     * @param [out] b example of out
     */ 
    double getArea(int& a,int& b) const;

    /**
     * @brief Create a new scaled Triangle object.
     * @return A new scaled Triangle object.
     */ 
    Triangle scale(const double factor) const;

private:
    /**
     * Lengths of side a, b, and c.
     */ 
    double mA, mB, mC;
};

/**
 * @brief Create a Triangle object
 * @param a The Length of triangle side a.
 * @return A Triangle object.
 * @param b The Length of triangle side b.
 * @param c The Length of triangle side c.
 */
Triangle createTriangle(const double a, const double b, const double c);

/**
 * @brief Determine if the three lengths provided could form a valid Triangle object.
 * @param a The Length of triangle side a.
 * @param b The Length of triangle side b.
 * @param c The Length of triangle side c.
 * @return true if the three lengths provided could form a valid Triangle object.
 * @return false if the three lengths provided could not form a valid Triangle object.
 */
bool isTriangle(const double a, const double b, const double c);
