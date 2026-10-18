{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  nativeBuildInputs = with pkgs; [
    pkg-config
    cmake
    gnumake
    gcc
  ];

  buildInputs = with pkgs; [
    # Dependências do Raylib para Linux / X11 / Wayland / OpenGL
    libX11
    libXrandr
    libXinerama
    libXcursor
    libXi
    libXext
    libGL
    wayland
    libxkbcommon
  ];
}