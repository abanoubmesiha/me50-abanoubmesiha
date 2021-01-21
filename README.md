# abanoubmesiha

#### Video Demo: https://youtu.be/onzg7VFkuE8
#### Description: Front-end Portofolio React App with some small projects

Here you can find a portofolio or CV which I have build with JS and CSS,
inside it you can find some small prjects and games that I've built while I am learning.

- Hi there, when you enter portofolio, you will notice that it's only front-end, made by JS and CSS languages.
- You can find sections for some info, previous work positions, education and courses.
- In the last section, you will find some projects I made while I am learning some technologies.
- The most recent one is the Jotto App, it has a secret word, and you should guess this word.
it's made by ReactJS and it's components are tested by Jest and Enzyme.
- I also made a simple calculator of income and expenses by AngularJS.
- I still learning NodeJS and still didn't finish it's project.
- lastely, you will find some games like Rock, Paper, and Scissors, X and O, and Pixel Art Maker.
**Here is some of the important files**
1. `resumeData.json` which has all the static data of the app.
2. `App.js` is the bigger parent of the React App.
3. `/Components` folder which has JSX files which represent the sections of the page imported in the `App.js` file.
4. `public/images` folder which has the thumbnails of the projects.
_Main Portfolio App Can be found in `abanoubmesiha-master.zip`_
* ## Jotto
#### A React / Redux app used to demonstrate testing
- Getting the secret word through an API and testing it.
- Redux controls the state of the App.
- Jest and Enzyme test components for props and state.
- Jest and Enzyme test methods through mocking.
**Here is some of the important files**
1. all `*.test.js` files are responsible of testing the files which have the same names.
2. `App.js` is the bigger parent of the React App.
3. `/helpers` have some helper functions you will use in testing files.
4. `/actions` have action creator functions which trigger the reducers to update the state.
5. `/reducers` responsible for updating parts of app state.
6. `configureStore.js` initiate the store with the middleware of thunk ( allows you to make async action creators ).
7. `/Components` folder which has JSX files which represent the sections of the page imported in the `App.js` file.

_Source Code of Jotto App is attached._

* ## Budget Calculator
#### An Angular JS app used to make simple calculations.
- Using some coloful UI
_Source Code of Budget Calculator App is attached._
---------------------------------------------------------------------
# Getting Started with Create React App

This project was bootstrapped with [Create React App](https://github.com/facebook/create-react-app).

## Available Scripts

In the project directory, you can run:

### `npm start`

Runs the app in the development mode.\
Open [http://localhost:3000](http://localhost:3000) to view it in the browser.

The page will reload if you make edits.\
You will also see any lint errors in the console.

### `npm test`

Launches the test runner in the interactive watch mode.\
See the section about [running tests](https://facebook.github.io/create-react-app/docs/running-tests) for more information.

### `npm run build`

Builds the app for production to the `build` folder.\
It correctly bundles React in production mode and optimizes the build for the best performance.

The build is minified and the filenames include the hashes.\
Your app is ready to be deployed!

See the section about [deployment](https://facebook.github.io/create-react-app/docs/deployment) for more information.

### `npm run eject`

**Note: this is a one-way operation. Once you `eject`, you can’t go back!**

If you aren’t satisfied with the build tool and configuration choices, you can `eject` at any time. This command will remove the single build dependency from your project.

Instead, it will copy all the configuration files and the transitive dependencies (webpack, Babel, ESLint, etc) right into your project so you have full control over them. All of the commands except `eject` will still work, but they will point to the copied scripts so you can tweak them. At this point you’re on your own.

You don’t have to ever use `eject`. The curated feature set is suitable for small and middle deployments, and you shouldn’t feel obligated to use this feature. However we understand that this tool wouldn’t be useful if you couldn’t customize it when you are ready for it.

## Learn More

You can learn more in the [Create React App documentation](https://facebook.github.io/create-react-app/docs/getting-started).

To learn React, check out the [React documentation](https://reactjs.org/).

### Code Splitting

This section has moved here: [https://facebook.github.io/create-react-app/docs/code-splitting](https://facebook.github.io/create-react-app/docs/code-splitting)

### Analyzing the Bundle Size

This section has moved here: [https://facebook.github.io/create-react-app/docs/analyzing-the-bundle-size](https://facebook.github.io/create-react-app/docs/analyzing-the-bundle-size)

### Making a Progressive Web App

This section has moved here: [https://facebook.github.io/create-react-app/docs/making-a-progressive-web-app](https://facebook.github.io/create-react-app/docs/making-a-progressive-web-app)

### Advanced Configuration

This section has moved here: [https://facebook.github.io/create-react-app/docs/advanced-configuration](https://facebook.github.io/create-react-app/docs/advanced-configuration)

### Deployment

This section has moved here: [https://facebook.github.io/create-react-app/docs/deployment](https://facebook.github.io/create-react-app/docs/deployment)

### `npm run build` fails to minify

This section has moved here: [https://facebook.github.io/create-react-app/docs/troubleshooting#npm-run-build-fails-to-minify](https://facebook.github.io/create-react-app/docs/troubleshooting#npm-run-build-fails-to-minify)
