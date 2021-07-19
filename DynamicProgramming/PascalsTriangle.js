/**
 * @param {number} numRows
 * @return {number[][]}
 */
const generate = function (numRows) {
  let pascalTriangle = [];
  for (let i = 0; i < numRows; i++) {
    const col = new Array(i + 1).fill(1);
    for (let j = 1; j < i; j++) {
      col[j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
    }
    pascalTriangle.push(col);
  }
  return pascalTriangle;
};
