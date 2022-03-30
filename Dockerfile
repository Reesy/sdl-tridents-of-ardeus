FROM node:stretch-slim

EXPOSE 3000

COPY ./embuild/resources ./embuild/resources

COPY ./embuild/index.html  \
     ./embuild/Tridents-of-Ardeus.data \
     ./embuild/Tridents-of-Ardeus.js \
     ./embuild/Tridents-of-Ardeus.wasm \
     ./embuild

RUN npm install -g serve

CMD ["serve", "-s", "./embuild"]