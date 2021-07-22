const maxSlidingWindow = (nums, k) => {
  let dq = [],
    ans = [];
  for (let i = 0; i < nums.length; i++) {
    if (dq.length != 0 && dq[0] == i - k) dq.shift();
    while (dq.length != 0 && nums[dq[dq.length - 1]] < nums[i]) dq.pop();
    dq.push(i);
    if (i >= k - 1) ans.push(nums[dq[0]]);
  }
  return ans;
};

console.log(maxSlidingWindow([1, 3, -1, -3, 5, 3, 6, 7], 3));
