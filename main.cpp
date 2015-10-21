#include <iostream>
#include <string>
#include <vector>


class JobRecord
{
private:
    int mStartYear;
    int mEndYear;
    std::string mJobTitle;
    std::string mCompanyName;

public:
    JobRecord(int StartYear, int EndYear, const std::string &JobTitle, const std::string &CompanyName) :
        mStartYear{StartYear}
      , mEndYear{EndYear}
      , mJobTitle{JobTitle}
      , mCompanyName{CompanyName}
    {

    }
    bool isValid() const
    {
        return !mJobTitle.empty()
                && ((mStartYear > 1960) && (mEndYear > 1960))
                && !mCompanyName.empty();
    }
};
class CV
{
private:
    std::string mName;
    int mBirthYear;
    std::string mSkills;
    std::string mPreviousJobs;

public:
    CV(const std::string &name, int birthYear, const std::string &skills, const std::string &previousJobs) :
        mName{name}
      , mBirthYear{birthYear}
      , mSkills{skills}
      , mPreviousJobs{previousJobs}
    {

    }

    void addJobRecord() const
    {

    }

    bool isValid() const
    {
        return !mName.empty()
                && ((mBirthYear > 1963) && (mBirthYear < 1995))
                && !mSkills.empty()
                && !mPreviousJobs.empty();
    }


    void print() const
    {
        if (isValid())
        {
            std::cout << mName << " (" << mBirthYear << ")" << std::endl;
            std::cout << "=====================" << std::endl;
            std::cout << "Skills: " << mSkills << std::endl;
            std::cout << "Previous work record: " << mPreviousJobs << std::endl;
            std::cout << std::endl;
        }
    }


};

int main()
{
    CV nazarsCV {"Nazar Senyk", 1968,"C++", "IBM 1990-1995; Microsoft 1996-2002"};

    CV richardsCV("Richard Hope", 1976, "Java", "IBM 1996-1997");

    CV hatikosCV("Hatiko", 1976, "Java", "IBM 1996-1997");

    std::vector<CV> cvList {nazarsCV, richardsCV, hatikosCV, {"Will Walker", 9997, "C++, Java", "IBM 1990-1999; Microsoft 1999-2010"} };

    for (const auto& cv: cvList)
    {
        if (cv.isValid())
        {
            cv.print();
        }
        else
        {
            std::cout << "ERROR: CV is invalid" << std::endl;
        }
    }

    return 0;
}
