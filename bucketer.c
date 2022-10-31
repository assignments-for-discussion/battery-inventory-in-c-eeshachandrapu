#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  struct CountsByUsage counts = {0, 0, 0};
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  int i;
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  for(i=0;i<numberOfBatteries;i++)
  {
    if(chargeCycleCounts[i]<410)
      counts.lowCount++;
    else if(chargeCycleCounts[i]>=410 && chargeCycleCounts[i]<950)
      counts.mediumCount++;
    else if(chargeCycleCounts[i]>=950)
      counts.highCount++;
  }
  printf("Done counting :)\n");
  printf("Number of low usage batteries: %d\n",counts.lowCount);
  printf("Number of medium usage batteries: %d\n",counts.mediumCount);
  printf("Number of high usage batteries: %d\n",counts.highCount);
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
