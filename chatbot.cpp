
# Install required libraries:
# pip install nltk newspaper3k scikit-learn numpy lxml_html_clean

# Import libraries
from newspaper import Article
import random
import string
import nltk
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.metrics.pairwise import cosine_similarity
import numpy as np
import warnings

warnings.filterwarnings('ignore')

# Download punkt package
nltk.download('punkt', quiet=True)

# Input Article
article = Article(
    'https://www.mayoclinic.org/diseases-conditions/chronic-kidney-disease/symptoms-causes/syc-20354521'
)

article.download()
article.parse()
article.nlp()

# Store article text as corpus
corpus = article.text

# Print article
print(corpus)

# Tokenize sentences
text = corpus
sentence_list = nltk.sent_tokenize(text)

# Print the list of sentences
print(sentence_list)


# Create bot response
def bot_response(user_input):
    user_input = user_input.lower()
    sentence_list.append(user_input)

    bot_response = ''

    cm = CountVectorizer().fit_transform(sentence_list)

    similarity_scores = cosine_similarity(cm[-1], cm)
    similarity_scores_lists = similarity_scores.flatten()

    index = np.argsort(similarity_scores_lists)
    index = index[1:]

    response_flag = 0
    j = 0

    for i in range(len(index)):
        if similarity_scores_lists[index[i]] > 0.0:
            bot_response = bot_response + ' ' + sentence_list[index[i]]
            response_flag = 1
            j = j + 1

        if j > 2:
            break

    if response_flag == 0:
        bot_response = bot_response + " I apologize, I don't understand."

    sentence_list.remove(user_input)

    return bot_response


# Create a function to return random responses to greetings
def greeting_response(text):
    text = text.lower()

    # Bot greetings
    bot_greetings = ['hii', 'hey', 'hello', 'hola']

    # User greetings
    user_greeting = ['hi', 'hey', 'hello', 'hola', 'greetings']

    for word in text.split():
        if word in user_greeting:
            return random.choice(bot_greetings)


# Start chatbot
print("Doc Bot: I am doc bot for your services. For a short time, I will answer your questions.")

exit_list = ['exit', 'see you later', 'bye', 'quit', 'break']

while True:
    user_input = input()

    if user_input.lower() in exit_list:
        print("Doc Bot: Chat with you later!")
        break

    else:
        if greeting_response(user_input) is not None:
            print('Doc Bot: ' + greeting_response(user_input))

        else:
            print('Doc Bot: ' + bot_response(user_input))

