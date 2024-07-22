#include "stats.h"
#include <numeric>
#include <algorithm>

using namespace Statistics;

Stats Statistics::ComputeStatistics(const std::vector<double>& dbVec_SensorData) {
    //Implement statistics here
	Stats mStStats = {};

	mStStats.average = ComputeAverage(dbVec_SensorData);
	mStStats.max = ComputeMax(dbVec_SensorData);
	mStStats.min = ComputeMin(dbVec_SensorData);

	return mStStats;
}

double Statistics::ComputeAverage(const std::vector<double>& dbVec_SensorData)
{
	return accumulate(dbVec_SensorData.begin(), dbVec_SensorData.end(), 0.0) / dbVec_SensorData.size();
}

double Statistics::ComputeMax(const std::vector<double>& dbVec_SensorData)
{
	return *max_element(dbVec_SensorData.begin(), dbVec_SensorData.end());
}

double Statistics::ComputeMin(const std::vector<double>& dbVec_SensorData)
{
	return *min_element(dbVec_SensorData.begin(), dbVec_SensorData.end());;
}

int main()
{
	Statistics::ComputeStatistics({ 1.5, 8.9, 3.2, 4.5 });
	return 0;
}