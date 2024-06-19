# Connect Four
This is a game of Connect Four on the commandline, including an AI opponent.

## Usage
The following is the output of `rlConnectFour --help`:
```
OPTIONS:
  -h, --help        Output this help text.
  --ai-count <x>    Use <x> AIs. Default is 1.
                    (<x> must be an integer between 0 and 2)
                    If this value is set to 1, player 1 is the human player.
  --no-color        Disable ANSI escape sequences for colors.
  --player1 <name>  Set the name of player 1 to <name>.
  --player2 <name>  Set the name of player 2 to <name>.
  --player2-first   Set player 2 to start.
                    By default, player 1 starts.
```


## Details
* When `--no-color` is __not__ set, tokens of both players are represented by `()`,
  with a red player 1 and a yellow player 2.
* When `--no-color` __is__ set, tokens of player 1 are represented by `()` and
  tokens of player 2 are represented by `[]`.
