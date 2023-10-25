#ifndef EX3_HealthPoints_H
#define EX3_HealthPoints_H

#include <iostream>


class HealthPoints
{
public:
    /*
    * Creator of HealthPoints class.
    *
    * @param amount - the starting max health and current hp.
     *              if not given, reset to DEFAULT_POINTS.
    *
    * @return
    *      A new instance of HealthPoints.
    */
    HealthPoints(int amount = DEFAULT_POINTS);


    /*
     * default copy constructor, assignment operator and destructor.
     */
    HealthPoints(const HealthPoints &) = default;
    HealthPoints& operator=(const HealthPoints &other) = default;
    ~HealthPoints() = default;

    /*
    * adds health to current hp, considering the boundaries.
    *
    * @param add - hp to add.
    *
    * @return
    *   A reference to the object (this).
    */
    HealthPoints &operator+=(int add);

    /*
    * reduce health points from current hp, considering the boundaries.
    *
    * @param reduce - hp to reduce.
    *
    * @return
    *   A reference to the object (this).
    */
    HealthPoints &operator-=(int reduce);

    /*
     * exception for putting non-positive value in the constructor.
     */
    class InvalidArgument : public std::exception {};

private:
    int m_points;
    int m_maxPoints;
    static const int DEFAULT_POINTS = 100;

    /*
     * makes sure health points are between 0 and max health.
     */
    void applyBoundaries();

    friend bool operator==(const HealthPoints &hp1, const HealthPoints &hp2);
    friend bool operator>(const HealthPoints &hp1, const HealthPoints &hp2);
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints &hp);

};

/*
* -----------------------------------------------------------------
*/


/*
* compares 2 HealthPoints objects only by current health points.
*
* @param hp1, hp2 - two HealthPoints objects to compare.
*
* @return
*       true - if current amount is equal.
*       false - otherwise.
*/
bool operator==(const HealthPoints &hp1, const HealthPoints &hp2);

/*
* compares 2 HealthPoints objects only by current health points.
*
* @param hp1, hp2 - two HealthPoints objects to compare.
*
* @return
*       true - if current amount is NOT equal.
*       false - otherwise.
*/
bool operator!=(const HealthPoints &hp1, const HealthPoints &hp2);

/*
* compares 2 HealthPoints objects only by current health points.
*
* @param hp1, hp2 - two HealthPoints objects to compare.
*
* @return
*       true - health in hp1 is greater than health in hp2.
*       false - otherwise.
*/
bool operator>(const HealthPoints &hp1, const HealthPoints &hp2);

/*
* compares 2 HealthPoints objects only by current health points.
*
* @param hp1, hp2 - two HealthPoints objects to compare.
*
* @return
*       true - health in hp1 is greater or equal than health in hp2.
*      false - otherwise.
*/
bool operator>=(const HealthPoints &hp1, const HealthPoints &hp2);

/*
* compares 2 HealthPoints objects only by current health points.
*
* @param hp1, hp2 - two HealthPoints objects to compare.
*
* @return
*       true - health in hp1 is smaller than health in hp2.
*       false - otherwise.
*/
bool operator<(const HealthPoints &hp1, const HealthPoints &hp2);

/*
* compares 2 HealthPoints objects only by current health points.
*
* @param hp1, hp2 - two HealthPoints objects to compare.
*
* @return
*       true - health in hp1 is smaller or equal than health in hp2.
*       false - otherwise.
*/
bool operator<=(const HealthPoints &hp1, const HealthPoints &hp2);

/*
* adds an integer to a HealthPoints object, when int from right.
*
* @param hp1 - HealthPoints object to add to.
*        num - integer to add.
*
* @return
*       HealthPoints current points as hp + num. (boundaries are not considered!)
*/
HealthPoints operator+(const HealthPoints& hp, int num);

/*
* adds an integer to a HealthPoints object, when int from left.
*
* @param hp1 - HealthPoints object to add to.
*        num - integer to add.
*
* @return
*       HealthPoints with same max points as hp and current points as hp + num.
*/
HealthPoints operator+(int num, const HealthPoints &hp);

/*
* subtracts an integer from HealthPoints object, when int from left.
*
* @param hp1 - HealthPoints object to subtract from.
*        num - integer to subtract.
*
* @return
*       HealthPoints with same max points as hp and current points as hp - num.
*/
HealthPoints operator-(const HealthPoints &hp, int num);


/*
* prints HealthPoints object to an output stream.
*
* @param os - output stream to print into
*        hp - HealthPoints object to print.
*
* @return
*       a reference to os.
*/
std::ostream& operator<<(std::ostream &os, const HealthPoints &hp);


#endif //EX3_HealthPoints_H
