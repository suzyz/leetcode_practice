package p355

const lim = 10

type tweet struct {
	id, time int
}

type Twitter struct {
	time     int
	followee map[int][]int
	tweets   map[int][]tweet
}

/** Initialize your data structure here. */
func Constructor() Twitter {
	t := Twitter{}
	t.time = 0
	t.followee = make(map[int][]int)
	t.tweets = make(map[int][]tweet)
	return t
}

/** Compose a new tweet. */
func (this *Twitter) PostTweet(userId int, tweetId int) {
	newTweet := tweet{
		id:   tweetId,
		time: this.time,
	}
	this.time++

	if _, ok := this.tweets[userId]; !ok {
		this.tweets[userId] = []tweet{newTweet}
	} else if len(this.tweets[userId]) < lim {
		this.tweets[userId] = append(this.tweets[userId], newTweet)
	} else {
		this.tweets[userId] = append(this.tweets[userId][1:], newTweet)
	}
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
func (this *Twitter) GetNewsFeed(userId int) []int {
	res := []tweet{}

	// followees's
	for _, p := range this.followee[userId] {
		for _, t := range this.tweets[p] {
			if len(res) < lim {
				res = append(res, t)
			} else {
				for i := 0; i < lim; i++ {
					if res[i].time < t.time {
						res[i] = t
						break
					}
				}
			}
		}
	}

	// oneself's
	for _, t := range this.tweets[userId] {
		if len(res) < lim {
			res = append(res, t)
		} else {
			for i := 0; i < lim; i++ {
				if res[i].time < t.time {
					res[i] = t
					break
				}
			}
		}
	}

	sort.Slice(res, func(i, j int) bool {
		return res[i].time > res[j].time
	})

	ans := make([]int, len(res))
	for i := 0; i < len(res); i++ {
		ans[i] = res[i].id
	}
	return ans
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
func (this *Twitter) Follow(followerId int, followeeId int) {
	n := len(this.followee[followerId])
	if n == 0 {
		this.followee[followerId] = []int{followeeId}
		return
	}
	for i := 0; i < n; i++ {
		if this.followee[followerId][i] == followeeId {
			return
		}
	}
	this.followee[followerId] = append(this.followee[followerId], followeeId)
}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
func (this *Twitter) Unfollow(followerId int, followeeId int) {
	n := len(this.followee[followerId])
	for i := 0; i < n; i++ {
		if this.followee[followerId][i] == followeeId {
			this.followee[followerId] = append(this.followee[followerId][:i],
				this.followee[followerId][i+1:]...)
		}
	}
}

/**
 * Your Twitter object will be instantiated and called as such:
 * obj := Constructor();
 * obj.PostTweet(userId,tweetId);
 * param_2 := obj.GetNewsFeed(userId);
 * obj.Follow(followerId,followeeId);
 * obj.Unfollow(followerId,followeeId);
 */
