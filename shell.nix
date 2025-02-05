{pkgs ? import <nixpkgs>{}}:

pkgs.mkShell{
	buildInputs = with pkgs; [
		SDL2
	];
	shellHook = '' 
		zsh
	'';
	postShellHook = '' 
		export PS1="%B%{$fg[blue]%}\![ %1d ] %# %b"
	'';

}
