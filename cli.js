#!/usr/bin/env node

const { spawnSync } = require("child_process");

const args = process.argv.slice(2);
const cmdArgs = args.length === 0 ? ["make"] : args;

const dockerArgs = [
  "run", "--rm",
  "-v", `${process.cwd()}:/app`,
  "libfm7",
  ...cmdArgs
];

const res = spawnSync("docker", dockerArgs, { stdio: "inherit" });
process.exit(res.status ?? 1);

