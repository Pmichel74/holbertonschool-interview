# Star Wars API - Characters Display

## 📋 Description

This project contains a Node.js script that displays all characters from a Star Wars movie using the Star Wars API (SWAPI). The script takes a movie ID as a parameter and displays the names of all characters in the order they appear in the API response.

## 🎯 Objective

The objective of this project is to demonstrate:
- Using REST APIs with Node.js
- Handling asynchronous HTTP requests
- Sequential data processing
- JSON manipulation

## 🔧 Prerequisites

- **Node.js**: Version 10.x or higher
- **npm**: To install dependencies
- **Operating System**: Linux, macOS, or Windows with WSL

## 📦 Installation

### 1. Clone the repository (if not already done)

```bash
git clone https://github.com/your-username/holbertonschool-interview.git
cd holbertonschool-interview/starwars_api
```

### 2. Install dependencies

```bash
npm install request
```

### 3. Make the script executable

```bash
chmod +x 0-starwars_characters.js
```

## 🚀 Usage

### Syntax

```bash
./0-starwars_characters.js <movie_id>
```

### Arguments

- `<movie_id>`: The Star Wars movie ID (number from 1 to 7)

### Movie IDs Mapping

| ID | Movie Title |
|----|-------------|
| 1  | A New Hope |
| 2  | The Empire Strikes Back |
| 3  | Return of the Jedi |
| 4  | The Phantom Menace |
| 5  | Attack of the Clones |
| 6  | Revenge of the Sith |
| 7  | The Force Awakens |

## 💡 Examples

### Example 1: Display characters from "A New Hope"

```bash
./0-starwars_characters.js 1
```

**Expected output:**
```
Luke Skywalker
C-3PO
R2-D2
Darth Vader
Leia Organa
Owen Lars
Beru Whitesun lars
R5-D4
Biggs Darklighter
Obi-Wan Kenobi
```

### Example 2: Display characters from "The Empire Strikes Back"

```bash
./0-starwars_characters.js 2
```

### Example 3: Without argument

```bash
./0-starwars_characters.js
```

**Output:**
```
Usage: ./0-starwars_characters.js <movie_id>
```

## 🏗️ Code Structure

### How it works

1. **Argument retrieval**: The script retrieves the movie ID from `process.argv[2]`
2. **Validation**: Checks that an ID was provided
3. **Main API request**: Performs a GET request to the `/api/films/{id}` endpoint
4. **Character extraction**: Parses the JSON response and extracts the list of character URLs
5. **Sequential requests**: For each character, performs a request to retrieve their name
6. **Display**: Displays the names in order using a recursive function

### Key function: `printCharacters`

This recursive function ensures that character names are displayed in the correct order, despite the asynchronous nature of HTTP requests.

```javascript
const printCharacters = (index) => {
  if (index >= characters.length) return;

  request(characters[index], (err, res, body) => {
    if (err) {
      console.error(err);
      return;
    }

    const characterData = JSON.parse(body);
    console.log(characterData.name);
    printCharacters(index + 1);  // Recursive call
  });
};
```

## 🌐 API Used

**Star Wars API (SWAPI)**: `https://swapi-api.hbtn.io/`

### Endpoints used

- **Films**: `GET /api/films/{id}`
- **Characters**: `GET /api/people/{id}`

### Response format (Film)

```json
{
  "title": "A New Hope",
  "episode_id": 4,
  "characters": [
    "https://swapi-api.hbtn.io/api/people/1/",
    "https://swapi-api.hbtn.io/api/people/2/",
    ...
  ],
  ...
}
```

## 📚 Dependencies

- **request**: Module for making HTTP requests (deprecated but used for this exercise)

```json
{
  "dependencies": {
    "request": "^2.88.0"
  }
}
```

> **Note**: The `request` module is deprecated. For new projects, it is recommended to use `axios`, `node-fetch`, or Node.js native `fetch` API (v18+).

## ⚠️ Error Handling

The script handles the following errors:
- Missing argument (movie ID not provided)
- HTTP request errors
- JSON parsing errors (implicit)

## 🔍 Technical Details

### Shebang

```javascript
#!/usr/bin/node
```

The shebang allows the script to be executed directly without typing `node` in front.

### Asynchronicity

The script uses callbacks to handle asynchronicity. The recursive `printCharacters` function ensures the characters are displayed in order.

## 🐛 Troubleshooting

### Error: "command not found"

```bash
chmod +x 0-starwars_characters.js
```

### Error: "Cannot find module 'request'"

```bash
npm install request
```

### Error: "Usage: ./0-starwars_characters.js <movie_id>"

You must provide a movie ID as an argument.

## 👥 Author

Project completed as part of the Holberton School program.

## 📝 License

This project is for educational purposes.

---

**Holberton School - Interview Preparation**
