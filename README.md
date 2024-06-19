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
  --no-banner       Hide the banner.
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



## Special games
The following are inputs that lead to special outputs in certain versions.

I discovered these while debugging and testing.

If your system buffers multi-line clipboard pastes as multiple separate inputs
(like `cmd.exe` and the `Windows Terminal` do under Windows), you can run the
entire game automatically by copying the number lines and pasting them (though
you will have to execute the last one manually via `Enter`).


### `v1.0.0.0` + `v1.0.0.1`
#### Win with ease
In version 1.0.0.0 and 1.0.0.1 (identical, except v1.0.0.1 is g++ compatible),
you could win by simply stacking in one column, as player order wasn't considered.
```
1
1
1
1
```

### `v1.0.1.0`
#### Almost win legitimately, but actually "win" due to an out-of-range move by the AI
```
4
7
7
7
2
4
2
2
5
5
3
3
2
1
1
5
7
1
1
```
