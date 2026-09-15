#!/usr/bin/env node

const { spawnSync } = require("child_process");

const args = process.argv.slice(2);
const cmdArgs = args.length === 0 ? ["make"] : args;

const image = process.env.LIBFM7_IMAGE || "ghcr.io/alexdev-at/libfm7:latest";

const dockerArgs = [
  "run", "--rm",
  "-v", `${process.cwd()}:/app`,
  image,
  ...cmdArgs
];

const res = spawnSync("docker", dockerArgs, { stdio: "inherit" });
process.exit(res.status ?? 1);

