function minCostClimbingStairs(costs) {
  let first = costs[0];
  let second = costs[1];
  let i = 0;
  if (costs.length <= 2) return Math.min(first, second);
  else i = 2;
  for (; i < costs.length; i++) {
    let current = costs[i] + Math.min(first, second);
    first = second;
    second = current;
  }
  return Math.min(first, second);
}
