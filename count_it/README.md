# Reddit API - Count Keywords in Hot Posts

## Description

This project implements a **recursive function** that queries the Reddit API to parse titles of all hot articles in a subreddit and prints a sorted count of specified keywords. The function is case-insensitive and counts word occurrences (not just titles containing the word).

## Features

- **Recursive implementation**: Uses recursion to paginate through all hot posts
- **Case-insensitive matching**: Keywords are matched regardless of case
- **Word boundary detection**: Only matches whole words (e.g., "java" won't match "javascript")
- **Duplicate keyword handling**: If a keyword appears multiple times in the word list, counts are multiplied
- **Sorted output**: Results sorted by count (descending), then alphabetically (ascending)
- **No redirects**: Handles invalid subreddits without following redirects

## Requirements

- Python 3.x
- `requests` library

Install dependencies:
```bash
pip3 install requests
```

## Usage

```bash
./0-main.py <subreddit> '<keyword1> <keyword2> ...'
```

### Examples

```bash
./0-main.py programming 'python java javascript'
```

Output:
```
java: 42
python: 21
javascript: 8
```

**With duplicate keywords:**
```bash
./0-main.py programming 'java java java python'
```

Output:
```
java: 126
python: 21
```

Note: `java` appears 3 times in the word list, so its count is multiplied by 3 (42 × 3 = 126).

## Function Prototype

```python
def count_words(subreddit, word_list)
```

### Parameters

- **subreddit** (str): Name of the subreddit to query
- **word_list** (list): List of keywords to count (case-insensitive)

### Return Value

None. The function prints results directly to stdout.

## How It Works

1. **Normalize keywords**: Convert all keywords to lowercase and track duplicates
2. **Recursive API calls**: Fetch hot posts page by page using the `after` parameter
3. **Parse titles**: Extract words from titles (alphanumeric characters only)
4. **Count occurrences**: Count each keyword appearance in all titles
5. **Apply weights**: Multiply counts by the number of times each keyword appears in word_list
6. **Sort results**: Sort by count (descending), then alphabetically (ascending)
7. **Print output**: Display results in the required format

## Key Implementation Details

### Word Extraction

The function properly handles punctuation by only matching alphanumeric characters:
- `"java"` ✓ matches
- `"java."` ✓ matches (extracts "java")
- `"java!"` ✓ matches (extracts "java")
- `"java_script"` ✗ doesn't match "java" (underscore breaks the word)

### Recursion

The function uses a nested recursive helper ([0-count.py:26-68](count_it/0-count.py#L26-L68)) that:
1. Fetches a page of hot posts (up to 100 per request)
2. Processes all titles on that page
3. Checks for the `after` token
4. Recursively calls itself with the `after` token to get the next page

### Invalid Subreddits

- Returns HTTP 404 or redirect status → prints nothing
- Uses `allow_redirects=False` to avoid following redirects to search results

## Files

- `0-count.py`: Implementation of the count_words function
- `0-main.py`: Test program demonstrating usage

## Example Code

```python
#!/usr/bin/python3
from 0-count import count_words

# Basic usage
count_words('programming', ['python', 'java', 'javascript'])

# With duplicate keywords
count_words('programming', ['java', 'java', 'java', 'python'])

# Invalid subreddit (prints nothing)
count_words('invalidsubreddit12345', ['test'])
```

## Testing

Test with various subreddits:

```bash
# Popular programming subreddit
./0-main.py programming 'python java c++'

# Gaming subreddit
./0-main.py gaming 'steam xbox playstation'

# Invalid subreddit (should print nothing)
./0-main.py thisisnotavalidsubreddit123 'test'
```

## Important Notes

- **Reddit API Rate Limiting**: The Reddit API may rate-limit requests. Use a proper User-Agent header (already included in the code).
- **Hot Posts Change**: Results may vary as Reddit's hot posts are constantly updated.
- **Case Sensitivity**: All matching is case-insensitive. "Python", "python", and "PYTHON" are treated as the same keyword.
- **Word Count vs Title Count**: The function counts word occurrences, not titles. If "java" appears 3 times in one title, it counts as 3.

## Author

Project completed as part of Holberton School
