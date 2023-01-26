there is a release every two months that is about 10 weeks

new release comes out one every 10 to 11 weeks

releases are time based rather then feature based, so releases are not held up for features

small incremental changes called patches
new features
enchancements
fix bugs

when a new kernel is relesed, there is 2 week merge window

during this period system maintainers send pull requests (before or during this window)

all major new develpment is added to the kernel during the merge window

rc = release candidate

as end of this merge window, the first release candidate is release with label rc1

once a relese gets it rc label, only bug fixes will be allowed to be merged further

parallely, rc2 and r3 will come out a week later and so on.. this conitunues until all major major bug fixes are over


this is full cycle

during a cycle that is one week before the merge window for lets say 5.1

new cycle starts 5.2 after 3 week quiet period that is from one week before 5.1 merge window 

bug fixes will be included in all stable releases that is rc1 bug coudl alse be adde din rc3

![[Pasted image 20230126020146.png]]

RC:

mainline kernel pre releases that are used for testing new features in the mainline.

Stable:

stable releases are bug fixes only, bug fixes will be backported from mainline tree

Long term:

seletected for long-term maintenance to provide ciritcal bug fixes for old kernel trees



Stable releases are normally only maintained for a few mainline release cycles, unless they are marked as long-term



