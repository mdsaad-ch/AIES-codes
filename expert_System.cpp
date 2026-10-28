Class Implementation:-
food(burger).
food(pizza).
food(sandwich).
lunch(sandwich).
dinner(pizza).
/*rules for meal planning*/
meal(X) :- food(X).

/*PS: create a mini expert system for wheather forcasting using Prolog. The system should be able to provide recommendations based on the weather conditions.*/
/*disease symptoms and diagnosis*/

% --- Facts: Define current weather parameters ---
temperature(28).
humidity(45).
precipitation(none).

% --- Rules: Weather Classification ---
weather(sunny) :- temperature(T), T >= 25, precipitation(none).
weather(rainy) :- precipitation(rain).
weather(cold)  :- temperature(T), T < 10.

% --- Rules: Recommendations ---
recommendation(sunny, "Wear sunglasses and sunscreen. Great day for a walk!").
recommendation(rainy, "Take an umbrella and wear waterproof boots.").
recommendation(cold,  "Wear a heavy jacket and a beanie.").

% --- Main Query ---
forecast :-
    weather(W),
    recommendation(W, Advice),
    format('Weather is ~w. Recommendation: ~w~n', [W, Advice]).
