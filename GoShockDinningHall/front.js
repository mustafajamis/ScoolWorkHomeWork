document.getElementById('nutritionForm').addEventListener('submit', function(event) {
    event.preventDefault();

    const calories = parseInt(document.getElementById('calories').value);
    const protein = parseInt(document.getElementById('protein').value);
    const carbs = parseInt(document.getElementById('carbs').value);
    const fat = parseInt(document.getElementById('fat').value);
    const goal = document.getElementById('goal').value;

    // Make a POST request to the ChatGPT API
    fetch('https://api.openai.com/v1/chat/completions', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
            'Authorization': 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 // My API KEY
        },
        body: JSON.stringify({
            model: 'gpt-3.5-turbo',
            messages: [
                {role: 'system', content: 'You are a helpful assistant that provides meal recommendations based on nutrition information.'},
                {role: 'user', content: `I need meal recommendations based on ${calories} calories, ${protein}g protein, ${carbs}g carbs, ${fat}g fat, and ${goal} goal.`}
            ]
        })
    })
    .then(response => response.json())
    .then(data => {
        const recommendationsDiv = document.getElementById('recommendations');
        recommendationsDiv.innerHTML = "<h2>Meal Recommendations:</h2>";

        const ul = document.createElement('ul');
        data.choices[0].message.content.forEach(recommendation => {
            const li = document.createElement('li');
            li.textContent = recommendation;
            ul.appendChild(li);
        });

        recommendationsDiv.appendChild(ul);
    })
    .catch(error => console.error('Error:', error));
});
