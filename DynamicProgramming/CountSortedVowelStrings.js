function countVowelStrings(n) {
  const chars = ["a", "e", "i", "o", "u"];
  let res = [];
  function dfs(word) {
    if (word.length === n) {
      res.push(word);
      return;
    }

    for (let i = 0; i < chars.length; i++) {
      if (chars[i] >= word.charAt(word.length - 1)) {
        dfs(word + chars[i]);
      }
    }
  }
  dfs("");
  return res.length;
}
